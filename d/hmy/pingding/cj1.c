// cj1.c
// Created by Numa 19991027

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����ƽ�����ڵ�һ�����֣�·���������������ַǷ�����Ϊ�˵غ����½�
��̳��ľ����ȥ��Զ�����Գ������Ķ����������������ƽ���ݽ��⡣
LONG
        );
        set("exits", ([ 
          "west" : __DIR__"gate1",
          "east" : __DIR__"cj2",
	]));
	set("objects",([
		__DIR__"npc/jiaozhong" : 2,
	]));
        set("outdoors", "ƽ����");
        setup();
}
