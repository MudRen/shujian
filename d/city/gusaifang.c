inherit ROOM;

void create()
{
        set("short", "�ĳ�");
        set("long", @LONG
������һ�������������䲻�󣬼����˼��ڷ������ˣ������м�����ӱ�
��վ��һλ��ʮ������ˣ���������ߺ�������һ������һ���ĳ����֣�����
��������ׯ�ҡ�ǽ�Ϲ���һ������(paizi)��
LONG
        );

        set("item_desc", ([
                "paizi" : "
ya tc <����> <coin|silver|gold> Ѻͷ��(����˳�򼰵�������ȷ)       һ����ʮ��
ya dc <����> <coin|silver|gold> Ѻ���(����������ȷ)               һ��ʮ��\n"
//	"ya sd <����> <coin|silver|gold> Ѻ˫��(������ͬ�Ҿ�Ϊż��)         һ��ʮһ\n"
"ya kp <����> <coin|silver|gold> Ѻ����(������ͬ�Ҿ�Ϊż��)         һ����
ya qx <����> <coin|silver|gold> Ѻ����(����֮��Ϊ��)               һ����
ya dd <����> <coin|silver|gold> Ѻ����(������Ϊ����)               һ����
ya sx <����> <coin|silver|gold> Ѻɢ��(����֮��Ϊ�����塢�š�ʮһ) һ���
ÿ�̰����ϵ��µ�˳��ֻ����һ�ֵ���(ͷ�ʺʹ�ʿ�ͬʱ����)�������������ׯ��Ӯ��
\n",
        ]));
        set("no_fight",1);
        set("sleep_room",1);
        set("no_sleep_room",1);
        set("exits", ([
                "north" : __DIR__"duchang",
        ]));
        set("objects", ([
                  __DIR__"npc/zhuangjia" : 1,
        ]));
        set("coor/x",90);
  set("coor/y",-30);
   set("coor/z",0);
   set("incity",1);
	setup();
}

int valid_leave(object me, string dir)
{
        if (dir == "north" && me->query("balance")<100)
        tell_object(me,"���ûǮ?!�´β�Ҫ����\n");
        return ::valid_leave(me, dir);
}
