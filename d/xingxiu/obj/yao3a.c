// yao3a.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{

       set_name(HIB"��ȼ�ı��Ƿ�"NOR, ({ "bingbo fen", "fen", "bingbo" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long",
                       "һ��͸�����������Ķ��ۡ��Ѿ���ȼ������Ϳ(tu)�ڱ������ˡ�\n" );
               set("unit", "Щ");
               set("base_value", 5000);
               set("base_unit", "��");
               set("base_weight", 30);
               set("drug_color", ""HIB"����ɭɭ"NOR"");
               set("poison", "bing_poison");
       }
       set_amount(1);
}

#include "yaoa.h";