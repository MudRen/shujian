//chelang2
//Csl 2000.04.26

inherit ROOM;
void create()
{
	set("short", "����");
	set("long",@LONG
ֻ���������ߣ�һ�ɸ������󣬲�ʱ�м�ֻ�������۷�ȿɰ��ķ�������
�Ĵ��ȼ�ɹ�������ͨ���Ժ��������һ�����ȡ�
LONG
        );
        set("exits",([
                "east"   :  __DIR__"chelang1",
                "north"  :  __DIR__"houyuan",
	]));

	setup();
}
