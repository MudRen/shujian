// modify by Lklv 2001.10.16
inherit ROOM;

void create()
{
	set("short", "��Ȼʯ��");
	set("long", @LONG
��������������ϳ��Ĵ��ش��������濴ֻ��һ������ʯɽ�ϵ���ͨ��Ȼ
ʯ������Ϊ�ص����ܣ����Ҷ��п���ʮ�ָ�������ɵ��ӱ㽫����������
һ�����ѵĴ��ؿ⡣
LONG);
	set("exits", ([
		"out" : __DIR__"xx2",
	]));
	set("objects", ([
                FOOD_D("hulu") : 2,
                MEDICINE_D("menghan_yao") : 1,
                MEDICINE_D("dujing_1") : 1,
//add by caiji                MEDICINE_D("qxs") : 1,
                ARMOR_D("armor"): 2,
		__DIR__"obj/fire" : 2+random(2),
        ]));
        setup();
}
