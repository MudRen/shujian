//  xue_men.c
//  Looklove y2k 4/26

inherit ROOM;

void create()
{
      set("short", "Ѧ������");
    set("long",@LONG
����������������ѦĽ����Ѧ��ҽ��ס����������Զ�ĺ����еĵط�
�Ѿ��ವ������û��˿���ưܵ����ӡ�һ�ȴ��ų��꿪�ţ���ǰ������ǰ����
ҽ�����ǣ������в��ٶ����ϴ�����������ʿ��
LONG
        );
	set("outdoors", "����");
        set("exits",([
                "south"  :  __DIR__"xiaohe",
                "north"  :  __DIR__"qiant",
                ]));

        set("objects", ([
                        __DIR__"npc/jiading" : 2,
                ]));

	setup();
}
