// Room: /d/city/chemahang.c ������

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ�������У�ר�������ŵ����⣬Ժ����ͣ�˼����󳵣�����ǽ
��λ���и���ǣ�����˨�˼�ƥ���Ա߶���һ�Ѹɲݡ�
LONG
	);
        set("xyjob", 1);
	set("exits", ([
                "south" : __DIR__"ncx2",
        ]));

	set("incity",1);
	setup();
}
