// yao3.c

#include <ansi.h>

inherit COMBINED_ITEM;

void create()
{

       set_name(HIB"���Ƿ�"NOR, ({ "bingbo fen", "fen", "bingbo" }) );
       if( clonep() )
               set_default_object(__FILE__);
       else {
               set("long","һ���Ա�󸶾֭���ϳ��ݵ�Ϊԭ���Ƴɵ�͸�����������Ķ��ۡ�
���Ե�(pour)����ˮ���Ϳ(tu)�ڱ����ϡ�(Ϳ֮ǰ�����ȵ�ȼ(dian)��)\n" );                                              
               set("unit", "Щ");
               set("base_value", 5000);
               set("base_unit", "��");
               set("base_weight", 30);
               set("drug2", "/d/xingxiu/obj/yao3a");
               set("poison", "bing_poison");
       }
       set_amount(1);
}

#include "yao.h";