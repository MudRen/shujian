//wuchang2.c
#include <ansi.h>
inherit ROOM;
int do_chuo(string arg);
int do_ti(string arg);
int do_pai(string arg);
int do_zhua(string arg);

void create()
{
        set("short", "�����䳡");
        set("long", @LONG
�����Ǹ�¶�����䳡���ſ�д��һ�����ӣ�paizi�����ö��������������
���ţ������ڳ��У�����û���˻�ͷ����һ�ۣ����ھ۾�����������Լ��Ĺ�
��ǽ�ǹ���һ�Ŵ���ɳ����shadai����һЩ��������ɳ��������
LONG
        );

        set("exits", ([
               "west" : __DIR__"wuchang1",
               "north" : __DIR__"zoulang1",
	       "east" : __DIR__"shilu3",
	       "south" : __DIR__"shilu2",
        ]));

        set("item_desc", ([
           "shadai"  :  "һ����ɳ�������������ϣ���������������(pai)����(ti)����(chuo)��ץ(zhua)��\n",
	   "paizi" :
		HIY"
������������������������������������
������������������������������������
����������                  ��������
��������   ��  ��  ��  ��   ��������
����������                  ��������     
������������������������������������
������������������������������������\n"NOR,
	]));

	set("outdoors","���");
		
        setup();
}

void init()
{
        add_action("do_chuo", "chuo");
        add_action("do_pai", "pai");
        add_action("do_ti", "ti");
        add_action("do_zhua", "zhua");
}

int do_chuo(string arg)
{
	object me;
        int costj, costq;
        me = this_player();
        if (me->is_busy()){
            write("��������æ����!\n");
            return 1;
        }
        if (me->is_fighting()){
            write("������ս����,�޷�ר�ĸɻ�!\n");
            return 1;
        }
        if ( !living(me)) return notify_fail("�㷢����? \n");
        
        if( objectp( me->query_temp("weapon")) )
            return notify_fail("ֻ�п��ֲ��ܴ�ɳ����\n");

        if ( !arg || arg != "shadai" ){
            write("�����ʳָ�ڿ����Ҵ�һͨ�������ڹ�����!\n");
            return 1;
        }
        costj = random((int)me->query("con"));
        costq = random((int)me->query("str"));

        if ((int)me->query("jingli") < costj || (int)me->query("qi") < costq){
            message_vision(HIR"$N��������, һ����С��,����ǽ��!\n"NOR,me);
            me->unconcious();
	    return 1;
	}
        
        me->receive_damage("jingli", costj);
        me->add("qi", -costq);       

        message_vision("$N������ָ����ɳ����ȥ��\n", me);

        if ( (int)me->query_skill("finger", 1) < 20 && random(10)>6 ){
            write(HIM"ɳ������ҡ�Σ��㲻֪������������Щ����ָ��!\n"NOR);
            me->improve_skill("finger", (int)(me->query("int") / 6));
        }
        return 1;
}

int do_ti(string arg)
{     
        object me;
        int costj, costq;
        me = this_player();
        if (me->is_busy()){
            write("��������æ����!\n");
            return 1;
        }
        if (me->is_fighting()){
            write("������ս����,�޷�ר�ĸɻ�!\n");
            return 1;
        }
        if ( !living(me)) return notify_fail("�㷢����? \n");
        
        if ( !arg || arg != "shadai" ){
            write("���ڿ�������һ���Ա��˿������Ц����!\n");
            return 1;
        }
        costj = random((int)me->query("con"));
        costq = random((int)me->query("str"));

        if ((int)me->query("jingli") < costj || (int)me->query("qi") < costq){
            message_vision(HIR"$N��������, һ����С�����˸���,ˤ�ڵ���!\n"NOR,me);
            me->unconcious();
	    return 1;
	}
        
        me->receive_damage("jingli", costj);
        me->add("qi", -costq);       

        message_vision("$N�������ȣ���ɳ����ȥ��\n", me);

        if ( (int)me->query_skill("leg", 1) < 20 && random(10)>6 ){
            write(HIM"���ɳ���ߵİ�����ȥ�������Լ��Ļ����ȷ��������!\n"NOR);
            me->improve_skill("leg", (int)(me->query("int") / 6));
        }
        return 1;
}

int do_zhua(string arg)
{
        object me;
        int costj, costq;
        me = this_player();
        if (me->is_busy()){
            write("��������æ����!\n");
            return 1;
        }
        if (me->is_fighting()){
            write("������ս����,�޷�ר�ĸɻ�!\n");
            return 1;
        }
        if ( !living(me)) return notify_fail("�㷢����? \n");
        if ( !arg || arg != "shadai" ){
       	    write("��˫����ץ������Χ��������һ��!\n");
            return 1;
        }
        costj = random((int)me->query("con"));
        costq = random((int)me->query("str"));

        if ((int)me->query("jingli") < costj || (int)me->query("qi") < costq){
            message_vision(HIR"$N��������, һ��������,ץ���Լ�����!\n"NOR,me);
            me->unconcious();
	    return 1;
	}
        
        me->receive_damage("jingli", costj);
        me->add("qi", -costq);       

        message_vision("$N������ָ����ɳ��ץȥ��\n", me);

        if ( (int)me->query_skill("claw", 1) < 30 && random(10)>6 ){
            write(HIM"�㲻�ϵ�ץ��ɳ���������Լ��Ļ���ץ���������!\n"NOR);
            me->improve_skill("claw", (int)(me->query("int") / 6));
        }
        return 1;
}

int do_pai(string arg)
{       
        object me;
        int costj, costq;
        me = this_player();
        if (me->is_busy()){
            write("��������æ����!\n");
            return 1;
        }
        if (me->is_fighting()){
            write("������ս����,�޷�ר�ĸɻ�!\n");
            return 1;
        }
        if ( !living(me)) return notify_fail("�㷢����? \n");
        if ( !arg || arg != "shadai" ){
            write("���������ģ��������Ա��˵�����!\n");
            return 1;
        }
        costj = random((int)me->query("con"));
        costq = random((int)me->query("str"));

        if ((int)me->query("jingli") < costj || (int)me->query("qi") < costq){
            message_vision(HIR"$N�������������Ʋ�ס��һ���Ŀգ�ˤ��һ��!\n"NOR,me);
            me->unconcious();
	    return 1;
	}
        
        me->receive_damage("jingli", costj);
        me->add("qi", -costq);       

        message_vision("$N�������ƣ���ɳ����ȥ��\n", me);

        if ( (int)me->query_skill("strike", 1) < 20 && random(10)>6){
            write(HIM"���ɳ���ĵĵ�����ȥ�������Լ��Ļ����Ʒ��������!\n"NOR);
            me->improve_skill("strike", (int)(me->query("int") / 6));
        }
        return 1;

}