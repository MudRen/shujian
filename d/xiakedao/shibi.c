// shibi.c ʯ��

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�����ǰ�ǿ��ĥ�⻬�Ĵ�ʯ��(shibi)�� ʯ�ڱ��ϵ�ȼ�Ű˸�
���ѣ���ҫ������ʯ��������ʮ���ˣ��е�עĿ��˼���еĴ�����
�����еı�Ŀ��������м����ڴ������硣
LONG );
        set("item_desc",([
                "shibi"  :
"\nʯ��������ʫ��\n\n\n"
"\t�ˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡ�\n"
"\t�ˡˡˡ����������������������������������������������������ˡˡ�\n"
"\t�ˡˡˡ��������������������������С������������������������ˡˡ�\n"
"\t�ˡˡˡ����������������������������������������������������ˡˡ�\n"
"\t�ˡˡˡ��Կ��Ϻ�ӧ���⹳˪ѩ���������հ����������ǡ����ˡˡ�\n"
"\t�ˡˡˡ����������������������������������������������������ˡˡ�\n"
"\t�ˡˡˡ�ʮ��ɱһ�ˣ�ǧ�ﲻ���У����˷���ȥ����������������ˡˡ�\n"
"\t�ˡˡˡ����������������������������������������������������ˡˡ�\n"
"\t�ˡˡˡ��й����������ѽ�ϥǰ�ᡣ������캥������Ȱ���������ˡˡ�\n"
"\t�ˡˡˡ����������������������������������������������������ˡˡ�\n"
"\t�ˡˡˡ�������Ȼŵ��������Ϊ�ᡣ�ۻ����Ⱥ����������������ˡˡ�\n"
"\t�ˡˡˡ����������������������������������������������������ˡˡ�\n"
"\t�ˡˡˡ����Իӽ𴸣��������𾪣�ǧ���׳ʿ���Ӻմ����ǡ����ˡˡ�\n"
"\t�ˡˡˡ����������������������������������������������������ˡˡ�\n"
"\t�ˡˡˡ����������㣬��������Ӣ��˭������£�����̫���������ˡˡ�\n"
"\t�ˡˡˡ����������������������������������������������������ˡˡ�\n"
"\t�ˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡˡ�\n",
        ]));
        
        set("no_clean_up", 0);

        set("exits", ([
 "west"  : "/d/xiakedao/dating",
                
        ]));
        setup();
        replace_program(ROOM);
}

/*
void init()
{
add_action("do_chuaimo", "chuaimo");    
}
int do_chuaimo(string arg)
{
        int i,p;
        int improve, cost, lv;
        object me = this_player();
        
        improve = me->query_int() / 10 + random(me->query_int() * 5 / 6);
        improve /= 2;
        if( !arg || arg=="" ) return 0;
        
        if( (int)me->is_busy() || me->is_fighting()) 
                return notify_fail("����æ���ء�\n");
                
        if (arg == "̫����" ){             
if(!me->query_temp("taixuan/qingtie") )  
                        return notify_fail("��Ϲ��Ħʲô?\n");
      
if( me->query_skill("taixuan-gong", 1) >= 100 )
                            return notify_fail("���Ѿ���̫�����ڻ��ͨ��!\n");


   tell_object(me,HIG"\n��Ŭ�����뿴��ʯ���ϵ����֣�����������Ӱ���໥�����ֻû�������С���������ǰ����...\n"NOR);
   tell_object(me,HIY"\nͻȻ�䣬���ƺ�ץ����ʲô...\n"NOR);
          tell_room(environment(me),HIC""+me->query("name")+HIC"�ƺ���˼����ʲô��һ����ü��չ�����ӡ�\n"NOR, ({}));
          
remove_call_out("do_chuaimo");
call_out("do_chuaimo",4+random(3), me);

        
          p=random(me->query("kar")+10);
      lv = me->query("max_pot")-100;
     
          if(p> 27 && me->query("kar")<31 )
      {
       tell_object(me,HIG"\n���������У�ͻȻ��������һ�С�\n"NOR);
       message_vision(HIC"\n$N������������Ц������˵������ԭ����ˣ�ԭ����ˡ���\n"NOR,me); 
         
       tell_object(me,HIR"�㿴�������ԣ���Ȼ��Ȼ�����ƺ�����Щ�ĵá�\n"NOR);
       

me->set("taixuan_pass",1);
       me->set_skill("taixuan-gong",lv);

me->delete("taixuan/qingtie");
CHANNEL_D->do_channel(this_object(), "rumor", HIW""+me->query("name")+"��Ե�ɺϣ�����ɡ�̫������ ��");
           i=180+random(40);
           
           
    }
    else
    {
       tell_object(me,HIG"\n���Ժ����ƺ�ץס��ʲô��������Ȼ���Ǻ����ס�\n"NOR);
       
       message_vision(HIC"\n$Nҡ��ҡͷ�������������Ǻ����ѵġ���˵�գ������̾�˿�����\n"NOR,me); 
me->delete_temp("taixuan/qingtie");
           

    
  }
  return 1;
}
}

*/
