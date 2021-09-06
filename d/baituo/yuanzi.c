#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��԰");
        set("long", @LONG
���Ǹ�����Ļ�԰���м�һ�Ѽ�ɽ��һ��СϪ���Ա������˸��໨�ݣ�
�������ˡ�������һ�����ŵ�����(tiemen)������ͨ����һ��Ժ�ӡ�
LONG);
        set("exits", ([
              "south" : __DIR__"tuitang",
        ]));
        set("objects", ([
                    FOOD_D("xiangjiao") : 1,
        ]));
        set("item_desc", ([                    
                "tiemen": "\n������ż�����أ�����û�м��ٽ���������������������Ϊ
�λ�����������ڴˣ�����һ���˶����Է�Խ(climb)�Աߵİ�ǽ��\n",
        ]));
        set("outdoors", "����ɽ");
        setup(); 
}

void init()
{
        add_action("do_fan", "fan");
        add_action("do_fan", "pa");
        add_action("do_fan", "climb");
        add_action("do_push", "push");
        add_action("do_push", "tui");
        add_action("do_push", "strike");
        add_action("do_wen", "wen");
        add_action("do_wen", "smell");                  
}

int do_fan(string arg)
{
        int dex, i = 0;
        object me = this_player();    
            
        dex = me->query_dex();     
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
        	
       	if( (int)me->query("hamagong") ) 
        	return notify_fail("�����뷭��ǽȥ��ͻȻ����һ�����ƿ����ŵĳ嶯��\n");
       	if (dex < 18 )
        	return notify_fail("�Ⱛǽ�䰫����ȴ��ôҲ������ȥ��\n");
       	
       	if (dex > 17 && dex < 25){  
           	message_vision("$N˫���ڰ�ǽ��һ����һ��������˹�ȥ��\n", me);
           	i = 1;
        	}
        
       	if (dex > 24 && dex < 36){  
           	message_vision("$N�˹���������һ�ݣ���Ծ�˹�ȥ��\n", me);
           	i = 2;
        	}
        
       	if (dex > 35){  
           	message_vision("$N�ż�����һ�㣬�߸�Ծ��Ʈ�˽�ȥ��\n", me);
           	i = 3;
        }    
        me->set_temp("baituo_climb", i);
        me->move(__DIR__"shetan");
        me->start_busy(2);
        return 1;   	    
}

int do_push(string arg)
{
        int str;
        object me = this_player();
        
        str = me->query_str();

        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
        	
        if( !arg || arg=="" ) return 0;
        
       	if (arg == "tiemen" ){
        	if( (int)me->query_skill("hamagong", 1)){
           		message_vision("$N�������ӣ���������������˫��ƽ���������š�\n", me);
           		message_vision("����ͻȻ�򿪣�$Nһû������˽�ȥ������ȴ�ֺ����ˡ�\n", me);
           		me->receive_damage("neili", 100);
           		me->receive_damage("jingli", 50);
           		me->move(__DIR__"yuanzi1");
           		message("vision", "ֻ��ž��һ����һ����Ӱ�����ų����˹�����\n",environment(me), ({me}));
           		return 1;
           		}
       		if (str < 21 )
               		return notify_fail("��ʹ���˳��̵��������ɾ����Ʋ��������š�\n");
               		
       		if (str > 20 && str < 38){  
       			if(str < 30)
           			message_vision("$Nʹ��ȫ�������������ţ�������ֻ���ᶯ��һ�¡�\n", me);
           		else message_vision("$N�˹������͵��������ţ����ŷ����˺����������������ϾͿ����ƿ��ˡ�����ʱ$N�������պ�ʹ�ֻ꣬�����ա�\n", me);
           		me->receive_damage("neili", 400);
           		me->receive_damage("jingli", 200);
           		return 1;
           		}

       		if (str > 37){  
           		message_vision("$N�ھ���ת��˫��ƽ���������š�\n", me);
           		message_vision("����ͻȻ�򿪣�$Nһû������˽�ȥ������ȴ�ֺ����ˡ�\n", me);
           		me->receive_damage("neili", 400);
           		me->receive_damage("jingli", 200);
           		me->move(__DIR__"yuanzi1");
           		message("vision", "ֻ��ž��һ����һ����Ӱ�����ų����˹�����\n",environment(me), ({me}));
           		return 1;
           		} 
       		}
       	else return 0;        
}

int do_wen(string arg)
{
        int con = this_player()->query_con();

      	if ( con > 29 && con < 37)
         	write("����������������ͻȻ�о����������������й���ζ�����Ų����Ǵ��Ķ����ġ�\n");      
      	if ( con > 36 )
         	write("����������������ͻȻ�о����������������й���ζ�������Ǵ������Ǳߵ�Ժ��Ʈ���ġ�\n");       
      	if ( con < 30 )
         	write("����������������ȫ�Ƿҷ��Ļ��㣬�㶼�����ˡ�\n");                     
       	return 1;        
}

int valid_leave(object me, string dir)
{        
       me->delete_temp("baituo_climb");
       return ::valid_leave(me);
}