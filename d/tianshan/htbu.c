// Room: /d/tianshan/htbu.c
// By Linux

inherit ROOM;

void create()
{
	set("short", "��첿");
	set("long", @LONG
��ǰ��һ�������������˵Ĵ�����Ϊ��첿�����ڵأ�����ǽ���ϻ�����
�����춥���ǵ�����ɫͼ������һ��ҹ�����ֲֳ棬����ǣ������ϵ������
������֮�ˣ������֮��ͬ���ܣ����������������Ժ���ʯĥ�ͣ��ֺ��޷죬
��Ȼ��ɡ������Ľǵ�����յ���ƣ������ڴ����������������Ǵӵ��﷢����
LONG);
	set("exits", ([
                "westdown" : __DIR__"dadao5",
        ]));       
        set("objects", ([
                __DIR__"npc/yupopo" : 1,
		__DIR__"npc/f-dizi" :1,
        ]));    
	setup();
}
