#include <stdio.h>
#include <mpfr.h>

int main(void)
{
    mpfr_set_default_prec(400000);

    mpfr_t a,b,t,p;
    mpfr_t a2,b2,t2,p2;
    mpfr_t temp1,temp2;
    mpfr_t pi;

    mpfr_init(a);
    mpfr_init(b);
    mpfr_init(t);
    mpfr_init(p);

    mpfr_init(a2);
    mpfr_init(b2);
    mpfr_init(t2);
    mpfr_init(p2);

    mpfr_init(temp1);
    mpfr_init(temp2);
    mpfr_init(pi);

    mpfr_set_ui(a,1,MPFR_RNDN);

    mpfr_set_ui(b,2,MPFR_RNDN);
    mpfr_sqrt(b,b,MPFR_RNDN);
    mpfr_ui_div(b,1,b,MPFR_RNDN);

    mpfr_set_d(t,0.25,MPFR_RNDN);

    mpfr_set_ui(p,1,MPFR_RNDN);

    for(int n=0;n<20;n++)
    {

        mpfr_add(temp1,a,b,MPFR_RNDN);
        mpfr_div_ui(a2,temp1,2,MPFR_RNDN);

        mpfr_mul(temp1,a,b,MPFR_RNDN);
        mpfr_sqrt(b2,temp1,MPFR_RNDN);

        mpfr_sub(temp1,a,a2,MPFR_RNDN);
        mpfr_mul(temp2,temp1,temp1,MPFR_RNDN);
        mpfr_mul(temp2,p,temp2,MPFR_RNDN);

        mpfr_sub(t2,t,temp2,MPFR_RNDN);

        mpfr_mul_ui(p2,p,2,MPFR_RNDN);

        mpfr_set(a,a2,MPFR_RNDN);
        mpfr_set(b,b2,MPFR_RNDN);
        mpfr_set(t,t2,MPFR_RNDN);
        mpfr_set(p,p2,MPFR_RNDN);
    }

    mpfr_add(temp1,a,b,MPFR_RNDN);
    mpfr_mul(temp1,temp1,temp1,MPFR_RNDN);

    mpfr_mul_ui(temp2,t,4,MPFR_RNDN);

    mpfr_div(pi,temp1,temp2,MPFR_RNDN);

    FILE *arquivo = fopen("pi_100000.txt","w");

    if (arquivo == NULL)
    {
    printf("Erro ao criar arquivo\n");
    return 1;
    }

    mpfr_fprintf(arquivo,"%.100000Rf\n",pi);

    fclose(arquivo);

    mpfr_clear(a);
    mpfr_clear(b);
    mpfr_clear(t);
    mpfr_clear(p);

    mpfr_clear(a2);
    mpfr_clear(b2);
    mpfr_clear(t2);
    mpfr_clear(p2);

    mpfr_clear(temp1);
    mpfr_clear(temp2);
    mpfr_clear(pi);

return
