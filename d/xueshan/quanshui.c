// Room: quanshui.c Ȫˮ��

inherit ROOM;

void create()
{
	set("short", "Ȫˮ��");
	set("long", @LONG
��ϥ���Ȫˮ������߻����������峺���ף�ˮ�в�ʱ��С���ڶ���ʯ��
������ȥ��
LONG
	);
        set("objects", ([
         __DIR__"npc/liefuyu" : 2, 
        ]));
	setup();
}

 void init()
  {
        int time;
        object me;
        me = this_player();
//        add_action("do_zhuo", "zhuo");
        add_action("do_tiao", "tiao");
        if (me->query("id")!=("liefu yu"))
         {
        time = me->query("con")*10;
        message_vision( 
        "$N�̵�����Ȫˮ�У�ˮ���Ľ������Ǳ����Ȫˮ��$Nֱ�����뿪��\n",me);
        remove_call_out("jumpout");
        call_out("jumpout",time,me);
     }
  }

/*int do_zhuo(string arg)
  {
        object me , weapon;
        me = this_player();
	weapon = me->query_temp("weapon");

        if ( arg != "yu" ) 
             return notify_fail("��������ˮ�к��һ����˼��£��ǣ�ˮ��������\n");

        if (((int)me->query_skill("dodge",1) < 120 )  || ((int)me->query_skill("claw",1) < 120 ))
        return notify_fail("������׾ٵؾͿ���ץ��С�㣬���������ջ�\n");
	if (objectp(weapon))
             return notify_fail("����"+weapon->query("name")+"��ˮ�����ػ�������������ˮ����\n");
        
	if (objectp(present("liefu yu", environment(me))))
          {
           if (random(10)>3) 
              {
         message_vision( 
        "$N������С�㣬׷��ȥ̽��ȥ׽����ˮ�˵û������졣��Ų֮�ʣ����ֱ���ǰ��������ࡣ\n",me);    
        me->add("qi", -50);
        me->add("jing", -50);
        me->add("neili", -50);
   
        me->improve_skill("dodge", me->query_skill("dodge")/5);   
        me->improve_skill("claw", me->query_skill("claw")/5);   
        return 1;
        }  

        me->add("qi", -30);
        me->add("jing", -30);
        me->add("neili", -30);
        message_vision( 
        "$N��ǰһ��������ȥ׽�����Ͻ���һ���������������˵���Ȫˮ�У�
$N��æ������ʪ���ܵ�����������\n",me);
         return 1;
         }

	return notify_fail("���ͷ���´������㶼�������ˣ���׽ʲôѽ��\n");
}*/


int do_tiao(string arg) 
   {
        object me;
        me = this_player();

        if(arg != "out" ) 
             return notify_fail("��������������������ˮ������Ṧ����ۿۡ�\n");
        message_vision("$N����ˮ̫���ˣ�ʵ���ܲ��ˣ�ֻ������Ȫˮ��\n",me);
	remove_call_out("jumpout");
        me->move(__DIR__"xuelingquan");
        tell_room(environment(me),"ֻ����������һ��ˮ�죬"+me->query("name")+"ʪ�����Ĵ�Ȫˮ�����˳�����\n");
	return 1;
}

void jumpout(object me)
	{
	if (!me) return;
        message_vision("$N����ˮ̫���ˣ�ʵ���ܲ��ˣ�ֻ������Ȫˮ��\n",me);
	remove_call_out("jumpout");
        me->move(__DIR__"xuelingquan");
        tell_room(environment(me),"ֻ����������һ��ˮ�죬"+me->query("name")+"ʪ�����Ĵ�Ȫˮ�����˳�����\n");
}
