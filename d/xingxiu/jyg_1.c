// Room: /d/xingxiu/kyg_1.c

inherit ROOM;

void create()
{
        set("short", "���ի�ֵ�");
        set("long", @LONG
�������ֺ�Ǯׯ���իλ�ڼ����صķֵ꣬���˴�Լ�м�ʮ���ˣ����
ի��ȫ�����ض��зֵꡣ�����е���Ʊ�����ǳ��ã�ͨ��ȫ����ǽ�Ϲ���һ
������(sign)��
LONG);
        set("no_fight", "1");
        set("exits", ([
                "north" : __DIR__"jyg",
        ]));

        set("item_desc", ([
                "sign" : "\n����������
        ����(check, chazhang, ����)
        ���(deposit, cun, ��)
        ȡ��(withdraw, qu, ȡ)
        �һ�(convert, duihuan, �һ�)

���еĽ�����ͭǮ����Ʊ��\n",
        ]) );
        set("objects", ([
                __DIR__"npc/huang" : 1,          
        ]));

        set("coor/x",-210);
  set("coor/y",60);
   set("coor/z",-10);
   setup();
}
