// /d/hmy/qiangu.c

inherit ROOM;

void create()

{
        
	set("short", "ǧ��ʯ");
	set("long",@long
����Ȫ������һ����ƺ����ƺ��������һ����̴��̵ľ�ʯ����������ǧ
��֮�ã�ʯ�ϱ�Ե����֪����������֡�ǧ��ʯ����
long);
        
	set("exits", ([ 
	    "north" : __DIR__"baizhang",

]));
       set("outdoors", "��ľ��");
        setup();
}
