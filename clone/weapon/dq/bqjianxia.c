// jianxia.c ������ϻ
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("��ϻ",({ "jian xia", "jianxia", "xia", "box" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("no_sell", 1);
                set("value", 100000);
                set("material", "wood");
                set("long", "����һ�������Ľ�ϻ��������һ�������̹ǵĺ��⡣\n");
                 }
        setup();
}
void init()
{
       add_action("do_break", "break");
       add_action("do_break", "zhen");
       add_action("do_break", "sui");
       add_action("do_break", "posui");
}

int do_break(string arg)
{
        object me,ob;
        me = this_player();
               
       if (!(arg=="xia" || arg == "jian xia" || arg == "jianxia" || arg == "box"))
       return 0;

if( (int)me->query("max_neili") < 3000)
		        {
                       write("������̫��,�����޷�����ϻ�ڱ�����\n");
			return 1;
				}
       
        if( (int)me->query_skill("sword", 1) < 180)
		        {
              write("�㽣������̫�ͣ����������ԣ��޷�������\n");
                 return 1;
				}
      
message_vision(HIY   "$N΢һ�þ�����ϻӦ���ƿ���ֻ���á��ˡ���һ����һ�������������ڿ��з����������̻�����������������\n" NOR, me);
            ob=new("/clone/weapon/youlong-jian");
            ob->move(me);
            ob->wield();
            destruct(this_object());
            return 1;
}
