// liangongfang.c ������

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������������ҵط��ż������ţ���λ�䵱��������ϥ��������
������
LONG
	);
	set("exits", ([
                "south" : __DIR__"zoulang1",
	]));
	set("objects", ([
               BINGQI_D("zhujian") : 1,
               BINGQI_D("mudao") : 1,
              BINGQI_D("fr_zhen") : 1,
        ]));
 
        setup();
}
