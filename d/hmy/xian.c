// /d/hmy/xian.c

inherit ROOM;

void create()
{
	set("short", "���˶�");
	set("long",@long
�߹�����ڣ����ȾͿ���һ��ʯ�����´�Ʈҡ���ɷ���ǣ�ֱ���ɼ��½磬
�������š�
long
);
        set("exits", ([ 
		"westdown" : __DIR__"xianren",
	]));
        
        set("outdoors", "��ľ��");
        setup();
}
