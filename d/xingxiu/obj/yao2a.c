// yao2a.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{

       set_name(HIR"��ȼ�ĺ��׷�"NOR, ({ "honglin fen", "fen", "honglin" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long",
                       "һ���Ⱥ�ɫ�Ķ��ۡ��Ѿ���ȼ������Ϳ(tu)�ڱ������ˡ�\n" );
               set("unit", "Щ");
               set("base_value", 5000);
               set("base_unit", "��");
               set("base_weight", 30);
               set("drug_color", ""HIR"�������"NOR"");
               set("poison", "hot_poison");
       }
       set_amount(1);
}

#include "yaoa.h";
