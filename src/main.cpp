//basic librairy
#include <iostream>
#include <string>
#include <vector>
#include<omp.h>

//lib include
#include "./my_lib/my_lib.h"
#include "./extern_lib/image.h"
#include "color.cpp"
#include "colorpixel.cpp"
#include "creation_scene.cpp"

using namespace std; //je suis un flemard, dsl

#define TAILLE_ECRAN 500
#define SAMPLE_PER_PIXEL 1

int main(){
    //on veut un peu de random
    srand(time(NULL));

    // creation de l'image image
    double ratio = 9./16;
    int largeur = TAILLE_ECRAN;
    int hauteur = int(TAILLE_ECRAN*ratio);
    vec2 resolution = vec2(largeur,hauteur);
    int nbChannels=3;
    vector<unsigned char> output(hauteur*largeur*nbChannels);
    string outputImage= "output.png";

    //on creer la scene
    scene world = creation_scene();

    //pour chaque pixel de l'image on veut calculer sa couleur
    #pragma omp parallel for
    for(int j = 0; j < hauteur; j++){
        for(int i = 0; i < largeur; i++){
            vec2 pos = vec2(i,j);
            color c = color_pixel(pos,resolution, world, SAMPLE_PER_PIXEL);
            write_color(c,(i+(hauteur-1-j)*largeur)*nbChannels,output);
        }
        if (omp_get_thread_num() == 0) cerr << 100.*j/hauteur*omp_get_max_threads() << "% \r";
    }

    //Final export
    cout << "Exporting.." << endl;
    int errcode = stbi_write_png(outputImage.c_str(), largeur, hauteur, nbChannels, output.data(), nbChannels*largeur);
    if (!errcode){
        cout<<"Error while exporting the resulting image."<<std::endl;
        exit(errcode);
    }

}