// xjroom2.c
// �η�
inherit ROOM;
void create()
{
	set("short","�η�");
	set("long",@long
������һ�������̵��η�������������ʪ���ȳ��˱ǣ��ڰ��в�ʱ����ʲ
ô��������űߡ������������˴����涼���þ�ʯ���ɵ�ʯǽ��ֻ��ͷ���и�
������ʯ��(flag)��
long);
      setup();
}

void init()
{        
     add_action("do_push","push");
}

int do_push(string arg)
{
    object me=this_player();
    object room;
    int qi;
    
    if(!arg)
        return 0;
    if(arg=="flag")
    {
        me->receive_damage("jing", 100);
        qi=(int)me->query_skill("dodge",1);
        qi=qi*me->query_kar()*me->query_dex()/900;
        if(qi>random(200))
        {
	    me->apply_condition("snake_poison",0);
            message_vision("$N���������ƶ��ϵ�ʯ�壬��Ȼ��$N�ƿ��ˣ�$N����������ȥ��\n",me);
	    room=find_object(me->query("uproom"));
	    if(!objectp(room))
		me->move("/d/sld/dukou");
	    else
            	me->move(room);
            tell_room(environment(me), "ͻȻ�ذ屻������һ�飬"+me->name() + "���������������� \n");
            tell_object(me, "������һԾ���������η���\n");
            /*ob->set_temp("number",(int)ob->query_temp("number",1)-1);
            if((int)ob->query_temp("number",1)==0)
                destruct(ob);*/
            //return 1;
        }
        else
        {
            message_vision("$N����������ͷ���ϵ�ʯ�壬����û�ƶ���\n",me);
	      //me->receive_damage("qi", 100);
            //return 1;
        }
    }
    else
        return 0;
    return 1;
}
	    	
