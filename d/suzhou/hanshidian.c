inherit ROOM;

void create()
{
        set("short", "��ʰ��");
        set("long",@long
���﹩�����ഫΪ���ͺ϶��ɡ�����ĺ�ɽ��ʰ�õĽ���������̬������
����ϲ������ɽ��ÿ���Ϧ��ҹ��ײ��һ������죬�京���ǳ���ӭ�ºͼ���
����һ�����λ��ɮ��
long);
	set("exits",([
		"out" : __DIR__"fengqiao",
		"west" : __DIR__"zhengdian",
	]));
	setup();
}
