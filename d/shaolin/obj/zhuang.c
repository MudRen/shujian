// tiexiang.c

inherit ITEM;
void setup()
{}


void create()
{
        set_name("÷��׮", ({"meihua zhuang", "zhuang"}));
        set_weight(2000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "����һ�������Ƴɵ�ľ׮����һ�����磬״��÷�����С�\n");
                set("unit", "��");
                set("material", "wood");
                set("no_get", "�������������뿪�Ƕ���\n");
        }
        setup();
}

void init()
{
    	add_action("do_jump","jump");
}

int do_jump(string arg)
{
      object me;
      me = this_player();
      if (!id(arg)) return 0;
         
      if(!(living(this_player()) || arg=="zhuang"))
	      return 0;
	if (me->is_busy() || me->is_fighting()) {
		write("����æ���ء�\n");
		return 1;
	}
      	if((int)me->query_skill("dodge",1)>101) {
          	write("����÷��׮�ϲ�ͣ�Ĵ�����ȥ�������޷�������Ṧ�ˡ�\n");
                return 1;   
      	}
	if((int)me->query("jingli")<30){
           	me->receive_damage("jingli",10);
           	write("�����һ�����ȣ���÷��׮��������ȥ��\n");
           	me->unconcious();
                return 1;
        }
//	if(me->query_skill("dodge",1)>=30&&!present("sha dai",this_player()))
	
//		return notify_fail("����������ȥ���޷�������ˡ�\n");
        	
     	if (me->query_skill("dodge",1)<31)
	{
		me->receive_damage("jingli",random(30)); 
		me->receive_damage("jing",random(30)); 
        	write("����÷��׮�ϲ�ͣ�Ĵ�����ȥ���Ի����Ṧ��������\n");
        	message_vision("$N����һԾ����÷��׮����׮�ϻ�����ȥ��\n", me);  
                me->improve_skill("dodge", me->query_dex());    
                return 1;
      	}
     	if ( present("sha dai", this_player()) &&  
           ((int)me->query_skill("dodge",1)>30) && 
           ((int)me->query_skill("dodge",1)<101))
     	{
        	me->receive_damage("jingli",random(30)); 
		me->receive_damage("jing",random(30)); 
        	write("����÷��׮�ϲ�ͣ�Ĵ�����ȥ���Ի����Ṧ��������\n");
        	message_vision("$N����һԾ����÷��׮����׮�ϻ�����ȥ��\n", me);  
                me->improve_skill("dodge", me->query_dex());    
                return 1;
      	}
      	return 1;                                  
}                                                                     
