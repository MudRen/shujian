//chelang1
//Csl 2000.04.26

inherit ROOM;
void create()
{
      set("short", "����");
    set("long",@LONG
ֻ���������ߣ�һ�ɸ������󣬲�ʱ�м�ֻ�������۷�ȿɰ��ķ�������
�Ĵ��ȼ��ɹ��������ǳ��ȣ�����ͨ���쾮��
LONG
        );
        set("exits",([
		"east"   :  __DIR__"tjing",
		"west"   :  __DIR__"chelang2",
		"south"   :  __DIR__"yaofang",
	]));

	setup();

}
