#include <weapon.h>
#include <ansi.h>

inherit BRUSH;
void create()
{
        set_name(HIR"���Ʊ�"NOR,({ "huoyun bi", "bi","brush" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

                set("unit", "��");
                set("value", 10000000);
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);    
                set("material", "steal");
		set("treasure",1);
                 set("wield_maxneili", 1000);
                set("wield_str", 30);
		set("long", HIR"����һ�ѳ����������ͭ�ʣ�ͨ�巺�죬��һ�Ż����ƶ䣬��������Ĺ�â��"NOR);
                set("wield_msg",HIR"ֻ�����һ����$N�Ѿ������Ʊʳ��������С�\n"NOR);             
                set("unwield_msg", HIR "$N˫����£�����һ���������Ʊ��������У�����Ʈ��֮����\n"NOR);               
        }
        init_brush(120);
        setup();
}

int do_wield(string arg)
{
       
        object me = this_player();
        if (!id(arg))
                return 0;      
        if((int)me->query_skill("guiyuan-tunafa", 1) < 120)
                return notify_fail("���޷�װ�����Ʊʡ�\n");
        if((int)me->query_skill("yingou-bifa", 1) < 120)
                return notify_fail("���޷�װ�����Ʊʡ�\n");

}
