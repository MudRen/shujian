// Room: /d/huashan/jiabi.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
	set("short", "��ɽ��");
	set("long", @LONG
һ����ڵ�ʯ��С·���ƺ���Ϊ���Ե�����ɽ��·�����ڹ⻬�羵��΢��
�������˷��׽�����
LONG
	);

	set("exits", ([
		"out" : __DIR__"siguoya",
	       "west" : __DIR__ "shiwu1",
           ]));
        set("objects",([
               __DIR__"npc/feng" : 1
                ])); 
   	setup();
}
 
