// Room: /d/xianyang/sishu.c ˽��
// Lklv 2001.9.22

inherit ROOM;
void create()
{
        set("short", "˽��");
        set("long", @LONG
����һ���¿��ŵ�˽�ӣ����ϵĶ�������������ȥ��û�ж������ӡ�һλ
�����˽���������ڵ������������Ų��ӡ���ԭ���Ǹ���ţ���Ϊ�ϴ�������
�ܣ�������û�����䣬û�취�ſ�ʼ���顣
LONG
        );
        set("xyjob", 1);
        set("exits", ([
                "north" : __DIR__"xcx5",
        ]));

        set("objects", ([
		__DIR__"npc/xiansheng" : 1,
        ]));

        set("incity",1);
	setup();
}
