// Room: /d/nanyang/yidao1.c
// Lklv Modify 2001.10.10

inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
���������������ϳ��ţ���Ϊ�����ش���������ȥ��Ҫ�壬����·������
���˺ܶࡣ�ϳ�������Ͼ��Ͽ��������������Ľŷ��Ƴ���С����������
�����������֡���ʱ��������������߷ɳ۶���������һ·������
LONG
	);
	set("exits", ([
		"south" : __DIR__"yidao",
		"north" : __DIR__"yidao2",
	]));
        set("objects", ([
                NPC_D("guanfu/bing") : 1,
                NPC_D("guanfu/wujiang") : 2,
        ]));
	set("outdoors", "����");
	setup();
}
