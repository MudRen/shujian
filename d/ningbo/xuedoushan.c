// /u/beyond/ningbo/xuedoushan.c ѩ�ɽ
inherit ROOM;
void create()
{
	set("short","ѩ�ɽ");
	set("long", @LONG
������ѩ�ɽ������ɽ������������գ�ɽ����ͻ���ˣ�����ͻأ���棬
���ٷ�����ѩ����ɫ����续������������ˮ�ڽ����ػ�ۣ������¿ڶ�Ȼ��
��ŭк���γɽ�����ѩ�ľ��١���̨Զ�������������羰�����㶯�ˡ�
LONG
     );
	set("exits",([ 
		"north" : __DIR__"dongqianhu",
	]));
        set("objects",([
		__DIR__"npc/you" : 1,
        ]));

	set("outdoors", "����");

	setup();
}
