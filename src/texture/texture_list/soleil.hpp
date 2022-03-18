#include "../texture.hpp"

class soleil : public material {
    private:
        color couleur_emis;
        color couleur_ref;
    public:
        soleil();
        soleil(color e);
        virtual color emittance(hit_record in) const override;
        virtual color reflexion(hit_record in, color c, vec3 out) const override;
        virtual vec3 rayon(hit_record h) const override;
};
