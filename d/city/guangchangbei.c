// Room: /d/city/guangchangbei.c

inherit ROOM;

void create()
{
	set("short", "�㳡��");
	set("long", @LONG
���ǹ㳡�ı��ࡣ�������������ڣ���ǰȥ���ŵ��˺��٣������ĵغ���
���塣���ڰ����Դӳ�Ҫ��ж���Ժ󣬳���������İ�����ԩ��ȥ���ԣ�����
��֪�����������Լ���ԩ�飬���������ܹ�Ϊ�Լ�����������������֣�����
�������������Ǳߡ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
	        "east" : __DIR__"beidajie3",
	        "west" : __DIR__"xidajie3",
         	"north" : __DIR__"yamen",
//          	"northwest" : __DIR__"leitai",
		"south" : __DIR__"guangchang",
               "northeast" : __DIR__"kongchang",
	]));
   	set("objects",([
   		__DIR__"npc/butou" : 1,
   	]));
   	set("incity",1);
	setup();
}

