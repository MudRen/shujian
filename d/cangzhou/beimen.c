// Room: /d/cangzhou/beimen.c

inherit ROOM;
string look_gaoshi();
void create()
{
        set("short", "����");
        set("long", @LONG
�����ǲ��ݳǵı����ţ�������ȥ�͵�������ˡ������Ķ������Ǻ��䣬
�ٱ��Ƕ������������ŵģ����������ؼ׵�ʿ�������Ѳ�һ�����ŵ��ӽ��ǵ�
�Ϻ���
LONG );
        set("exits", ([
                "north" : __DIR__"nroad1",
        	"south" : __DIR__"beijie1",
	]));
        set("item_desc", ([
                "gaoshi" : (:look_gaoshi:),
        ]));

	set("objects", ([
                NPC_D("guanfu/wujiang") : 1,
                NPC_D("guanfu/bing") : 2,
        ]));
	set("outdoors", "����");

	setup();
}

string look_gaoshi()
{
        return FINGER_D->get_killer() + "\n����֪��\n����ͨ\n";
}
