//wuchang3.c
#include <ansi.h>
inherit ROOM;

int do_tiao(string arg);

void create()
{
        set("short", "�����䳡");
        set("long", @LONG
�����Ǹ�¶�����䳡���ſ�д��һ�����ӣ�paizi�����ö��������������
���ţ������ڳ��У�����û���˻�ͷ����һ�ۣ����ھ۾�����������Լ��Ĺ�
�򣬳��ӵĶ�����һ��ɳ��(shakeng)��
LONG
        );
	set("item_desc",([
            "paizi" :
		HIY"
������������������������������������
������������������������������������
����������                  ��������
��������   ��  ��  ��  ��   ��������
����������                  ��������     
������������������������������������
������������������������������������\n"NOR,
            "shakeng" : "һ����ɳ�ӣ�����С������������������(tiao)Ծ��\n",
	]));

	set("outdoors","���");

        set("exits", ([
               "east" : __DIR__"wuchang4",
               "west" : __DIR__"shilu4",
	       "south" : __DIR__"bingqiku",
        ]));
	
        set("objects", ([
                  __DIR__"npc/jiaotou" : 1,
        ]));

        setup();
}

void init()
{
        add_action("do_tiao", "tiao");        
}

int do_tiao(string arg)
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

        if ( !arg || arg != "shakeng" ){ 
            write("���ڳ�����ı������˰��죬���˻���Ϊ�㷢�񾭣�\n");
            return 1;
        }
        costj = random((int)me->query("con"));
        costq = random((int)me->query("str"));

        if ((int)me->query("jingli") < costj || (int)me->query("qi") < costq){
            message_vision(HIR"$N����һ������һ������ɳ����ˤ�˸�����ʺ!\n"NOR,me);
            me->unconcious();
	    return 1;
	}
        
        me->receive_damage("jingli", costj);
        me->add("qi", -costq);       

        write("�����ӵ�������������һ����\n");

        if ( (int)me->query_skill("dodge", 1) < 20 && random(10)>6 ){
            write(HIM"�㲻�ϵ���ɳ�������ţ��Լ��Ļ����Ṧ�������!\n"NOR);
            me->improve_skill("dodge", (int)(me->query("int") / 6));
        }
        return 1;
}
