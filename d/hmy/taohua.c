// /d/hmy/taohua.c

inherit ROOM;

void create()
{
        set("short", "�һ���");
	set("long", @LONG
�ߵ��һ�����ǰ��һ����ɫ��ʯ��һ���������Բʯ�Է嶥�̽���ȥ����
��ƬƬ�һ�����������һ����
LONG
        );
        set("exits", ([ 
	  "northup" : __DIR__"meimao",
	  "westup" : __DIR__"zisi",
	  "west" : __DIR__"ziyun",
	]));
        set("outdoors", "��ľ��");

        setup();
}
