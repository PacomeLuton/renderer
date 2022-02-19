//basic librairy
#include <iostream>
#include <string>
#include <vector>

//lib include
#include "./my_lib/my_lib.h"
#include "./extern_lib/image.h"
#include "color.h"
#include "colorpixel.h"

using namespace std; //je suis un flemard, dsl

#define TAILLE_ECRAN 1000
#define SAMPLE_PER_PIXEL 4

int main(){
    // creation de l'image image
    double ratio = 9./16;
    int largeur = TAILLE_ECRAN;
    int hauteur = int(TAILLE_ECRAN*ratio);
    vec2 resolution = vec2(largeur,hauteur);
    int nbChannels=3;
    vector<unsigned char> output(hauteur*largeur*nbChannels);
    string outputImage= "output.png";


    //pour chaque pixel de l'image on veut calculer sa couleur
    for(int i = 0; i < largeur; i++){
        for(int j = 0; j < hauteur; j++){
            vec2 pos = vec2(i,j);
            color pixel_color = color_pixel(pos,resolution);
            for (int s = 0; s < SAMPLE_PER_PIXEL-1; ++s) {
                auto u = i + random_double();
                auto v = j + random_double();
                vec2 pos = vec2(u,v);
                pixel_color += color_pixel(pos,resolution);
            }
            color c = pixel_color/SAMPLE_PER_PIXEL;
            write_color(c,(i+(hauteur-1-j)*largeur)*nbChannels,output);
        }
    }

    //Final export
    cout << "Exporting.." << endl;
    int errcode = stbi_write_png(outputImage.c_str(), largeur, hauteur, nbChannels, output.data(), nbChannels*largeur);
    if (!errcode){
        cout<<"Error while exporting the resulting image."<<std::endl;
        exit(errcode);
    }

}