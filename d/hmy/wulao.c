// /d/hmy/wulao.c ���Ϸ�
inherit ROOM;

void create()
{
	set("short", "���Ϸ�");
	set("long", @LONG
�˴�������ʯ������࿿��ʯ�����϶�����������Ĳ������Ʈ��������
�����ϡ����λ�����������һ�㡣����Զ�����̣����･�࣬��ǰ����һ��
��Ⱥ(houqun)�������¡�
LONG
    );
        set("exits",([
            "west" : __DIR__"lianhua",
            "east" : __DIR__"ziyun",
            "north" : __DIR__"yiping",
            "south" : __DIR__"rusheng",
        ]));
        set("objects", ([
                __DIR__"npc/houzi": 2,
                __DIR__"npc/xiaohou": 2,

	]));
	set("outdoors", "��ľ��");	
	set("item_desc", ([
        	"houqun" : "��Ⱥ�����������֣�һ�����·�ڣ�һ���ִ��Ϸ嶥��\n",
	]));
	setup();
}
