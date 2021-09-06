// By River 98/12/
// LinuX@SJ 2004/03/09

#include <ansi.h>
inherit ROOM;

mapping valid_special = ([
        "death"  	:       1800,
        "per"		:	3800,
        "recover"	:	4000,
]);
mapping special_to_chinese = ([
        "death"  	:       "һ��"HIY"��Ч����"NOR,
        "per"  		:       "һ��"HIG"������ò"NOR,
        "recover"	:	"�ָ�һ��"HIB"������ʧ"NOR,
]);

int Change_credit(int credit, int chg, string arg);

void create()
{
        set("short", "������");
	set("long", @LONG
���Ǵ����˾�����أ��ӹܵ���Ҫ��һЩ����֮��ľ��׺���⣬��˸�
���к��壬���壬�����壬�����壬׳���Ա��һ������ʾ���������⣬����
������ͨ�룬�Ա�Ѷ�ʡ���������̬���ͣ���������ǰ���嵭����
LONG
	);
	//�����������Ϊ�齣���ֵ����У�����Ҳ���������������ǰ����һ��ܴ�ı���(sign)
	set("exits",([ 
             "north" : __DIR__"nanjie2",
        ]));
	set("no_fight",1);
        set("objects", ([
                __DIR__"npc/yayi" : 2,
        ]));
    
	set("coor/x",-320);
  	set("coor/y",-470);
   	set("coor/z",-20);
   	setup();
}

/*void init()
{
    add_action( "do_exchange", "exchange" );
    add_action( "do_exchange", "duihuan" );
    add_action( "do_look", "look" );
}
*/
// ��ȡ����
int GetMyCredit()
{
	object me = this_player();
	mixed ret = dbquery("SELECT U_Credit FROM Users WHERE U_Username=\""+me->query("id")+"\"");

	if (!ret)
	{
		write("���ݿ�����ʧ�ܡ�\n");
		return 0;
	}

	if (sizeof(ret) != 1)
	{
		write("���ݿ����������⣬���������Ա��ϵ��\n");
		return 0;
	}

	return ret[0][0];

}

int do_look(string arg)
{
        object me = this_player();
        string *p;
        int i;
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("����æ���ء�\n");
        	
        if (arg == "sign" ){   
	        p = sort_array(keys(valid_special), 1);
	        write(CHINESE_D->get_title("������������ʾ"));
	        write("��ǰ��ת�������������£�("HIG"������������µ���������"NOR")\n");
	        write("��������������������������������������������������������\n");
	        write(sprintf("   %-15s��  %-20s  %-12s\n", "��������ID","������������", "��Ҫ����"));
	        write("��������������������������������������������������������\n");
	        for (i=0;i<sizeof(p);i++) {
	                write(sprintf("   %-15s��  %-20s  %-12s\n", p[i],special_to_chinese[p[i]], chinese_number(valid_special[p[i]])+"��"));
	        }
	        write("��������������������������������������������������������\n");
	        write("����(exchange ��������ID) ����ת��\n\n");
               	return 1;
        }     
        return 0;
}

int do_exchange(string arg)
{
        int credit;
  	object me = this_player();
  	      
        if( me != this_player(1) ) return 0;
        if (me->is_busy())
		return notify_fail("����æ���ء�\n");

        credit = GetMyCredit();
        if (!arg || arg=="") {
                tell_object(me,"��Ŀǰ�����齣����Ϊ��"+chinese_number(credit)+"�㣬�ۼ�ʹ���齣����Ϊ��"+ chinese_number(me->query("credit")) +"�㡣\n");
                return 1;
        }
        
        switch( arg )
    	{
    			case "death":
		        if ( credit > valid_special[arg] )
		        {
		            if (Change_credit(credit, valid_special[arg], arg)){
		            me->add( "death_times", 1 );
		            me->add( "death_count", 1 );
		            return 1;
		            }
		        }
	        	break; 
	        	
	            	case "per":
		        if ( credit > valid_special[arg] )
		        {
		            if ( me->query( "per" ) > 29 ){
	                	tell_object(me,"���Ѿ��㹻���ˡ�\n" );
	                	return 1;
                	    }	
		            if (Change_credit(credit, valid_special[arg], arg)){
			            me->add( "per", 1 );
			            return 1;
		            }
		        }
	        	break; 
	        	
	        	case "recover":
		        if ( credit > valid_special[arg] )
		        {
		            if (Change_credit(credit, valid_special[arg], arg)){
			            "/cmds/wiz/recover"->do_recover(me, 1);
			            return 1;
		            }
		        }
	        	break; 
        default:                 
        tell_object(me,"��Ҫ��ʲô��\n" );
        return 1;
   	}
    	tell_object(me,"����齣���ֲ������㵱ǰ�Ļ����ǣ�" + chinese_number(credit) + "�㣬�һ�"+special_to_chinese[arg]+"��Ҫ"+chinese_number(valid_special[arg])+"�㡣\n" );
    	return 1;
}
int Change_credit(int credit, int chg, string arg)
{
	mixed ret;
	object me = this_player();
	
	ret = dbquery("UPDATE Users SET U_Credit=U_Credit-"+chg+" WHERE U_Username=\""+me->query("id")+"\"");
	if (!ret)
	{
		write("���ݿ�����ʧ�ܡ�\n");
		return 0;
	}

	me->add("credit",chg); //�Ѿ����ѵ��齣����
	me->start_busy(1+random(2));
	log_file("static/EXCHANGE", 
		sprintf("%s(%s) use %d credit(%d/%d) to exchange %s, ", 
		 me->name(1), geteuid(me), chg, credit, me->query("credit"), arg));
		 
	tell_object(me,"�㽫" + chinese_number(valid_special[arg]) + "���齣���ֶһ�Ϊ"+special_to_chinese[arg]+"��\n");
	tell_object(me,"��Ŀǰʣ����齣����Ϊ��"
			+ chinese_number(credit)+"�㣬�ۼ�ʹ���齣����Ϊ��" 
			+ chinese_number(me->query("credit")) +"�㡣\n");
	return 1;

}