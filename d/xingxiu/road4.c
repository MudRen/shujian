inherit ROOM;

void create()
{
        set("short", "���ﳤ��");
        set("long", @LONG
���������ﳤ�ǵļ����ˣ���ǽ�ߴ��ʵ�����治ʱ�������׵�ʿ��
�������߶�Ѳ�ߡ������߱��������ı߹ء������ء�������ͨ����ԭ������
���ȶɹ��ƺӡ�
LONG);
	set("exits", ([
		"southeast" : "/d/lanzhou/wuwei",
		"west" : __DIR__"fangpan",
	]));

	set("outdoors", "������");

	setup();
}
