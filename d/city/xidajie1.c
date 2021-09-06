// Room: /d/city/xidajie1.c
// Lklv modify 2001.9.27 ���ˣ�һ��ؼҿ�

inherit ROOM;
void quarter_pass();

void create()
{
	set("short", "�����");
	set("long", @LONG
������������ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ���ϵ����˱�
��ǰҲ������࣬���������ݵ������羰�����������������������š��ϱ���
һ���鱦�꣬����������һ�����¥�����š�̫���ŷ硱���������Ŷ�������
һ�����ң����������ƹݡ����ֲ�����������, ���ǹ�������ֱʡ��������
�������㴹�����Ρ�
LONG
	);
        set("outdoors", "����");

	set("exits", ([
		"east" : __DIR__"xidajie2",
                "south" : __DIR__"zhubaodian",
		"west" : __DIR__"ximen",
		"north" : __DIR__"jiulou",
	]));

        set("objects", ([
                CLASS_D("gaibang/qnqigai") : 1,
        ]));
	set("incity",1);
	setup();
	quarter_pass();
}

void quarter_pass()
{
	mixed *local;

	local = localtime(time() * 60);
	if (local[2] < 6 || local[2] >= 21) {
		set("long", @LONG
������������ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ���ϵ����˱�
��ǰҲ������࣬���������ݵ������羰�����������������������š��ϱ���
һ���Ѿ������˵��鱦�꣬����������һ���Ѿ������˵Ĵ��¥������һ����
�����Ŷ�������һ�����ң��ڰ�֮�п���̫�����ϵ��ּ���
LONG
		);
		delete("exits/north");
		delete("exits/south");
	}
	else {
		set("long", @LONG
������������ϣ��е�����Ľ���Ҫ�ȱ𴦵ĸɾ������ࡣ���ϵ����˱�
��ǰҲ������࣬���������ݵ������羰�����������������������š��ϱ���
һ���鱦�꣬����������һ�����¥�����š�̫���ŷ硱���������Ŷ�������
һ�����ң����������ƹݡ����ֲ�����������, ���ǹ�������ֱʡ��������
�������㴹�����Ρ�
LONG
		);
		set("exits/north", __DIR__"jiulou");
		set("exits/south", __DIR__"zhubaodian");
	}
	call_out("quarter_pass", 30);
}
