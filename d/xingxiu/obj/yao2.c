// yao2.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{

       set_name(HIR"���׷�"NOR, ({ "honglin fen", "fen", "honglin" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long", "һ�����߶����ϳ��ݵ�Ϊԭ���Ƴɵ��Ⱥ�ɫ�Ķ��ۡ�
���Ե�(pour)����ˮ���Ϳ(tu)�ڱ����ϡ�(Ϳ֮ǰ�����ȵ�ȼ(dian)��)\n");                       
               set("unit", "Щ");
               set("base_value", 5000);
               set("base_unit", "��");
               set("base_weight", 30);
               set("drug2", "/d/xingxiu/obj/yao2a");
               set("poison", "hot_poison");
       }
       set_amount(1);
}

#include "yao.h";