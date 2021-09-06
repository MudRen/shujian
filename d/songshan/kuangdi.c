// Room: /u/swl/songshan/kuangdi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����ھ�����һƬ���أ�ʮ�ֹ����ǰ�ĵ������������ʱ����
�����������Ｏ������������ȴ�����������ɻ�ϵĳ�����
LONG);
	set("exits", ([ 
            "south" : __DIR__"taishi-que",
            "north" : __DIR__"damen",
        ]));
	set("outdoors", "��ɽ");
	set("coor/x",40);
  set("coor/y",260);
   set("coor/z",110);
   setup();
}

void init ()
{
    object me = this_player();
	string m,m_i;
        int sk;
	
	if (!me->query("family") || me->query("family/family_name") != "��ɽ��")
		return;
	m_i = me->query("family/master_id");
	m = me->query("family/master_name");
    sk = me->query_skill("songshan-qigong",1);
	if (sk)
	{
		if (m_i == "shi dengda" || m_i == "di xiu" || m_i == "wan daping")
		{	
			me->set("family/generation",7);
			me->set_skill("hanbing-zhenqi",me->query_skill("songshan-qigong",1));
			me->delete_skill("songshan-qigong");
			tell_object(me,"ϵͳ�Ѿ���������ɽ�����Զ�ת��Ϊ����������\n");
			return;
		}
		if (m_i == "le hou" || m_i == "lu bo" || m_i == "ding mian" || m_i == "fei bin" || m_i == "tang yinge")
		{
			me->set("family/generation",6);
			me->set_skill("hanbing-zhenqi",me->query_skill("songshan-qigong",1));
			me->delete_skill("songshan-qigong");
			tell_object(me,"ϵͳ�Ѿ���������ɽ�����Զ�ת��Ϊ����������\n");
			return;
		}
		if (m_i == "zuo lengchan")
		{
			me->set("family/generation",4);
			me->set_skill("hanbing-zhenqi",me->query_skill("songshan-qigong",1));
			me->delete_skill("songshan-qigong");
			tell_object(me,"ϵͳ�Ѿ���������ɽ�����Զ�ת��Ϊ����������\n");
			return;
		}
	}
	return;
}
