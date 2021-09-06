// /d/meizhuang/jianyu.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", BLU"÷ׯ����"NOR);
	set("long", @LONG
����ںڰ������������ֲ�����ָ��Ψһ�Ĺ�������ǽ�Ϻ�������
�����͵ơ����Ϻ�ǽ�ϲ����˰���ɫ��Ѫ�ۣ�ɢ�����������������ϴ�
���Ĵ�Ϣ���������ĵ�����ص�������ë����Ȼ���ӵ��ε�ǽ����͸��
�������⡣������һ�Ƚ��յ����š�
LONG
	);
	set("item_desc", ([
		"door" : "�����ƺ���ǰ���˶���ʲô�ֽš�\n",
		"��"   : "�����ƺ���ǰ���˶���ʲô�ֽš�\n",
	]) );
	
			set("objects", ([
		"d/meizhuang/npc/renwoxing" : 1,
				]) );
				set("item_desc", ([
                "man": "�������ͬϡ��һ�㣬˫Ŀ��ɢ��û��һ����ɡ��������ƺ�ֻʣ��
��һ���ɿݵ����ǣ�Ȼ��ȴ����һ��������������������ţ�Ҳ���
�԰������´�����\n",
        ]));

	set("valid_startroom","1");

	set("coor/x", 3510);
	set("coor/y", -1420);
	set("coor/z", -10);
	setup();
}

void init()
{
	add_action("do_push", "push");
	add_action("do_move", "move");
}

void check_trigger()
{
	object room;
	if( (int)query("trigger")==8 && !query("exits/out") )
	{
		message("vision","�����ű����Ƶ��ѿ���һ����϶���պÿ����������ȥ��\n", this_object() );
		set("exits/south", __DIR__"didao7");
		if(!( room = find_object(__DIR__"didao7")) )
			room = load_object(__DIR__"didao7");
		message("vision", "������ͻȻ�ѿ�һ��խ�졣\n", room );
		room->set("exits/north", __FILE__);
		delete("trigger");
		call_out("close_passage", 5);
	}
}

void close_passage()
{
	object room;

	if( !query("exits/south") ) return;
	message("vision","��������ѽѽһ���죬���һ���ֹ����ˡ�\n", this_object());
	if( room = find_object(__DIR__"didao7") )
	{
		message("vision", "��������ѽѽһ���죬���һ���ֹ����ˡ�\n", room);
		room->delete("exits/north");
	}
	delete("exits/south");
}

int do_push(string arg ,string dir)
{
	object me;
	me = this_player();

		
	if( !arg || arg=="" )
	{
		write("��Ҫ��ʲô��\n");
		return 1;
	}
	
	if (me->query_skill("xixing-dafa",1) < 200)
		{
	write(HIR"\n���������Ǵ�̫���ˣ����³�ȥ�ֵ���ס÷ׯ���ѵĹ��������ǸϿ��ж����Ǵ󷨰ɡ�\n"NOR);
	return 1;
     }
if (me->query_skill("xixing-dafa",1) >= 200 && me->query("quest/xxdf/pass"))
		{
	write(HIW"\n��������ţ�ͻȻ��������������·���������������ɵ��������װ��������ס�Լ����ֽš�\n"NOR);
	write(HIG"\n�㷢�־�Ȼ�Ǻڰ��ӽ����ˣ���û�еȺڰ���˵������һԾ�������ο�ס�ڰ��ӵ����󡣡���\n"NOR);
	write(HIC"\n�ڰ���ֻ��������й���죬��ǿ����������ʱ��ֹ��ס���������վ����⣬һ��һ��֮�ʣ�\n"
	"�����������й����ʱ��������ֺ�ϵ���ʹ��ֻ�������ܴӷ������ѳ�����Ȼ����һֻ��\n"
	"һֻ��Ҳ�Ǹ�Ը��һ�뵽�˴������ֱ�ȥ����ν�����������ôһ���������ϡ��ڹء���\n"
	"��ء�����Ѩ�����翪��������ȱ�ڣ���ʱȫ��������к�����������ˮ���̣���Ҳ����\n"
	"�½ء��ڰ���֪��ֻ�����ߵ�һ�̣�ȫ�������㾡�����Է���ȥ�����·���������䳤����\n"
	"ҧ�����ݣ��ٽ��������������Լ��ֱۿ��ϡ�����ôһʹ�����������ڶ������������˵�\n"
	"һ���������˹�ȥ��\n\n"NOR);
  write(HIR"�㲻�����߶�ʮһ���򿪼������ţ�һ·�񱼣����Ƨ��С·�ɱ�������һ�����˵�ɽҰ��Ȼ��\n"
  "һ·С�ܵ��ﺼ�ݳǰ׵̡��㷢���Լ����Ѹ�ݷɱ���ͣ����ʱ���Ȳ�ƣ�ۣ�Ҳ����������֮��\n"
  "��֮ǰ���ƺ���������ʤ�������Ȼ���ְ׵���վ��һ�����ˡ�\n\n"NOR);
  
  write(HIG"�����ж�����ٺٺٵ�Ц�Ŷ���˵����С�ӣ���������ҷ��ϣ��Ҿ������㣬���ǣ���Ը�����Ϊʦ��\n"NOR);
  me->move("d/hz/baidi");
  me->set_skill("qixian-wuxingjian",1);
  write(HIG"�����ж�����ٺٺٵ�Ц�Ŷ���˵������ϧ�������̵��ӣ��Ҿͽ�÷ׯ��ׯ���������ν���������ɣ�\n"NOR);
  message_vision(HIC"\n��ġ��������ν��������ˣ���\n"NOR,me); 

	return 1;
     }
	if( arg=="door" || arg == "��")
	{
		add("trigger", 1);
		write("\n�������������Ž����ŵ����ţ��ƺ���һ���ɶ�....\n");
		check_trigger();
		return 1;
	}
	return 1;
}

void reset()
{
	::reset();
	delete("trigger");
}

int do_move(string arg)
{       
        int i;
        object me;
        object ob;      

        me = this_player();
        i =me->query("kar");
        
        
        if (arg != "man")
                return notify_fail("��Ҫ��ʲô��\n");

        if (me->query_temp("get_xxbook"))
                return notify_fail("��û��Ȥ�������������"
                                   "���ˣ�����ֻ�����뿪���\n");

        if (!me->query_temp("quest/xxdf/startlass") 
                || random(i) < 28
        	||  me->query("combat_exp") - me->query("quest/xxdf/fail_exp") <100000
        	|| time()-me->query("quest/xxdf/time")<86400 
        	 )
        {
                write(HIY"������ǰȥ��ȴ�������˵�����������һ��ϸϸ��ȱ�ڣ����ҿ���ȥǰ������������Ť������
������Щ�Ի󣬲�֪����ʲô���أ����ԾͲ����������ˡ�\n"NOR);
    write(HIG"����������ת������ã�Ҳû�з���ʲô�ر�ĵط������Ǿ��ƿ����ţ�ת�����˳�ȥ��
����ô˵����ǹ��죬���ɾ����� ���ǾͲ�����𣬵���һ�������ĳ���÷ׯ��
�����׵̣���ϸ���룬���������˴���ʯ��������������ϧ�Ѿ������������аûڡ�\n"NOR);
               me->delete_temp("quest/xxdf/start");
        
            me->set("quest/xxdf/fail_exp", me->query("combat_exp") );
            me->set("quest/xxdf/time",time());
            me->add("quest/xxdf/fail,1");
            
      tell_object(me,HBBLU"\n�ܿ�ϧ���㱾�γ��Խ������Ǵ�ʧ�ܣ�\n"NOR);
      tell_object(me,HBBLU"��Ŀǰ�ľ�����" + me->query("combat_exp") + "������ʱ�����齣"+ NATURE_D->game_time() + "�����¼��\n"NOR);
      tell_object(me,HBBLU"�㽫�ڼ��24Сʱ������100Kʵս���������һ�λ��ᣡ��\n\n"NOR);                   
               me->move("d/hz/baidi");
                return 1;
        }
        

        
        

        write(HIW"����ϸ���˿����ͣ���������Ȼ�Ǿ����Ƴɣ�ȴ��һ��ϸϸ��ȱ�ڣ�
���ֶ���Ҳ����ס�ˣ��㲻����ȻʧЦ���漴���Ǹ�����һϢ����
����������������ͻȻ����ԭ�����Ͽ���һЩ�֣��㲻����Щ�ɻ�
���ǽ�������������׼�������о����漴�����룬����������̵�
��Ĩȥ��Ȼ����Ǹ������·ŵ����ϣ�������ᡣ\n\n"NOR);

        if(i >30) {
         me->die(); 
        return 1;
        }

        me->set("quest/xxdf/pass", 1);
        me->delete_temp("quest/xxdf/start");

        ob = new("/d/meizhuang/obj/xixing-book");
        ob->move(me, 1);
        
        
        CHANNEL_D->do_channel( this_object(), "rumor",sprintf(HIM"��˵%s��÷ׯ���λ��һ��"HIR"���Ǵ��ر�"NOR"��", me->name(1)));
        
        write(HIY"\n��ɹ��������е���������һ�����Ǵ��ر���\n"NOR);
        log_file("quest/xixing",sprintf("%8s%-10s��÷ׯ���γɹ�������Ǵ��ر�����ɽ��%4d���䵱��%4d��ʧ�ܣ�%2d������%2d��\n",
			me->name(1),"("+capitalize(me->query("id"))+")",me->query("job_time/��ɽ"), 
			me->query("job_time/�䵱"), me->query("quest/xxdf/fail"),me->query("kar")),me);

        return 1;
}
