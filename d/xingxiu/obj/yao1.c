// yao1.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{

       set_name(WHT"���׷�"NOR, ({ "yinlin fen", "fen", "yinlin" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long","һ���Թǻҡ��ߵ���Ϊԭ���Ƴɵ����������Ķ��ۡ�
���Ե�(pour)����ˮ���Ϳ(tu)�ڱ����ϡ�(Ϳ֮ǰ�����ȵ�ȼ(dian)��)\n" );
               set("unit", "Щ");
               set("base_value", 5000);
               set("base_unit", "��");
               set("base_weight", 30);
               set("drug2", "/d/xingxiu/obj/yao1a");
               set("poison", "cold_poison");
       }
       set_amount(1);
}

#include "yao.h";
