// Room: /dlhg/zhengmen.c

inherit ROOM;
#include <wanted.h>
#include <ansi.h>
#include <room.h>

string look_gaoshi();

void create()
{
        set("short", "�ʹ�����");
        set("long", "����Ǵ���ʹ����š�Ρ����ΰ�ĳ�ǽ�ϣ���"HIY"ʥ�ȹ�"NOR"����������ʮ�����ۣ�
���ƻԻ͡�Ϧ�������������ϣ���̻Իͣ�����ĿΪ֮ѣ��һ�����Ž�ߵĸ�
ʾ(gaoshi)����ǽ�ϣ���������������ԡ�·�Ի�����һ���Ʒ�(paifang)��\n");

        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
                "paifang":HIC"\n\t\t��  �� ʥ   ��   ��   �� ��  ��\n\n"NOR, 
        ]));

        set("exits", ([
                "north" : __DIR__"zoulang1",
                "south" : "/d/dali/qsjie2",
        ]));
        set("objects", ([
                __DIR__"npc/shiwei" : 4,

        ]));
        set("outdoors", "����");
        set("coor/x",-310);
  set("coor/y",-440);
   set("coor/z",-20);
   setup();
}

string look_gaoshi()
{
        return HIY"
\t\t����������������������������������
\t\t������                      ������
\t\t������  "HIR"�ʹ��ص�  ����Ī��"HIY"  ������
\t\t������                      ������
\t\t����������������������������������\n"NOR;
}

int valid_leave(object me, string dir)
{
	if (dir == "north" && is_wanted(me))
		return 0;
	if (dir=="north" && objectp(present("huanggong shiwei", this_object()))) {
		if (me->query("qinwang"))
			message_vision(HIY"�������������ض�$N˵������ԭ����"
				+(string)me->query("qinwang")+"��������������\n"NOR, me
			);
		else if (me->query_skill("qiantian-yiyang")&&!me->query("tls"))
			message_vision(HIY"�������������ض�$N˵������ԭ���������������ˣ�������������\n"NOR, me); 
		
		else if (me->query_temp("huanggong") )
			message_vision(HIY"�������������ض�$N˵������ԭ���������������ˣ�������������\n"NOR, me); 
		
		else {
			if (me->query("gender") == "Ů��")
				return notify_fail("������ǰ��ס�㣬����˵�����ʹ��صأ�����Ѱ���̻�Ů�����ɳ��롣\n");
			if (me->query("gender") == "����") 
				return notify_fail(
					"������ǰ��ס�㣬����˵���������Ǵ���Ļʹ������Ǿ��ǵ��Ͻ��ǣ�������ذɡ�\n"
				);
			if (me->query("gender") == "����") 
				return notify_fail("����������ס������˵�����ʹ��صأ�����Ѱ�����Ұ�����ɳ��롣\n");
		}
	}      
	return ::valid_leave(me, dir);
}
