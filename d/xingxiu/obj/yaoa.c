// poison_dust.c
#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{

       set_name("��ȼ�Ķ����", ({ "duchong fen", "duchong", "fen" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long",
                       "һ������򼡢֩���Ϊԭ���ƳɵĶ��ۡ��Ѿ���ȼ������Ϳ(tu)�ڱ������ˡ�\n" );
               set("unit", "Щ");
               set("base_unit", "��");
               set("base_weight", 30);
               set("drug_color", ""BLU"��������"NOR"");
               set("poison", "xx_poison");
       }
       set_amount(1);
}

#include "yaoa.h";
