// emptyroom.c
// by augx@sj  2/26/2002
// this room for group guard when they are killed just and wait for revive

inherit ROOM;

void create()
{
	set("short","�շ���");
	set("long","����������������������ǰ�޺��ǰ��ɾ�������֮����\n");
	set("outdoors", "group");
	set("no_clean_up",1);
	setup();
}

int clean_up()
{
	return 1;
}
