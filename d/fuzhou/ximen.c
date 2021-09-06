// Room: /d/fuzhou/ximen.c
// Lklv 2001.9.10

inherit ROOM;

string look_gaoshi();
void quarter_pass();

void create()
{
        set("short", "����");
        set("long", @LONG
�����Ǹ��ݸ������ţ���ǽ���Ǻܸߣ���һ���еȹ�ģ�ĳ��š���������
����������ӣ������봨�����Ͽɴ����㣬ֱ���ƹ���˳��������Ŀ���һ
��ܶࡣ�����Աߵĳ�ǽ��������һֽ��ʾ(gaoshi)��
LONG
        );

	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));

	set("exits", ([
                "east" : __DIR__"xijie2",
                "west" : __DIR__"wroad",
	]));

        set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));

        set("outdoors", "����");
	setup();
        quarter_pass();
}

void quarter_pass()
{
        string local;

        local = NATURE_D->query_daytime();

        switch(local){
            case "event_night":
            case "event_midnight":
                  set("long", @LONG
�����Ǹ��ݸ������ţ���ǽ���Ǻܸߣ���һ���еȹ�ģ�ĳ��š���������
����������ӣ������봨�����Ͽɴ����㣬ֱ���ƹ���˳��������Ŀ���һ
��ܶࡣ��Ϊ������ҹ�������Ѿ����ˣ�������ʱ�޷����ǡ������Աߵĳ�
ǽ��������һֽ��ʾ(gaoshi)��
LONG);
        	  delete("exits/west");
                  break;
            default: set("long", @LONG
�����Ǹ��ݸ������ţ���ǽ���Ǻܸߣ���һ���еȹ�ģ�ĳ��š���������
����������ӣ������봨�����Ͽɴ����㣬ֱ���ƹ���˳��������Ŀ���һ
��ܶࡣ�����Աߵĳ�ǽ��������һֽ��ʾ(gaoshi)��
LONG);
                  set("exits/west", __DIR__"wroad");
        	  break;
        }
        call_out("quarter_pass", 60);
}

int valid_leave(object me, string dir)
{
          if (dir =="west" )
        if(present("guan bing", (environment(me)))
        && me->query_condition("killer") > 0)
                return notify_fail("�ٱ����еĵ���ס�����ȥ·��\n");
        return ::valid_leave(me, dir);
}
string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n����Ѳ��\n";
}
