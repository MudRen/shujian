// xjroom1.c
// ����1
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
����һ��������ר�������Ը����˵����壬����������ʪ���ȳ��˱ǣ�
�ڰ��в�ʱ�ػ���ʲô��������űߡ�������������������ڶ��ǳ��⻬��
û��ʲô���Դ��ֵĵط�������Ҫ��ȥ�������£������(climb)���ԡ�
long);
      setup();
}

void init()
{        
     add_action("do_climb","climb");
}

int do_climb(string arg)
{
    object me=this_player();
    object room;
    int qi;
    
    if(!arg)
        return 0;
    if(arg=="up")
    {
        qi=(int)me->query_skill("dodge",1);
        qi=qi*me->query_kar()*me->query_dex()/900;
        if(qi>random(100))
        {
            me->apply_condition("snake_poison",0);
            message_vision("$N����������������ȥ��\n",me);
	    room=find_object(me->query("uproom"));
	    if(!objectp(room))
		me->move("/d/sld/dukou");
	    else
            	me->move(room);
           
            message_vision("$N�����ش���������������! \n",me);
            /*ob->set_temp("number",(int)ob->query_temp("number",1)-1);
            if((int)ob->query_temp("number",1)==0)
                destruct(ob);*/
            //return 1;
        }
        else
        {
            message_vision("$N����������������ȥ�����ã�$Nһʧ�ֵ�����ȥ��\n",me);
            me->receive_wound("qi", 50);
	      me->receive_damage("qi", 50);
            //return 1;
        }
    }
    else
        return notify_fail("��������������\n");
    return 1;
}
	    	
