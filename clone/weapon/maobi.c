// maobi.c ë��
// by iceland

#include <weapon.h>
inherit SWORD;

void create()
{
        set_name( "ë��", ({  "mao bi" , "maobi" , "bi"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "֧");
                set("long", "һ֧������д��ë�ʣ����Ʊʸˣ�����������������ƮƮ�ġ�\n");
                set("value", 5);
                set("material", "wood");
              }
        init_sword(1);
        setup();
}