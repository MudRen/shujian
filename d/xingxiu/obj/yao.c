// poison_dust.c
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{

       set_name("�����", ({ "duchong fen", "duchong", "fen" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long",
                       "һ������򼡢֩���Ϊԭ���ƳɵĶ��ۡ�
���Ե�(pour)����ˮ���Ϳ(tu)�ڱ����ϡ�(Ϳ֮ǰ�����ȵ�ȼ(dian)��)\n" );
               set("unit", "Щ");
               set("base_value", 3000);
               set("base_unit", "��");
               set("base_weight", 30);
               set("drug2", "/d/xingxiu/obj/yaoa");
               set("poison", "xx_poison");
       }
       set_amount(1);
}
#include "yao.h";

