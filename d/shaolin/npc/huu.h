

#include <ansi.h>
string* names = ({
        "juechan shiren",
        "bichan shiren",
        "kuchan shiren",
        "kongchan shiren",
        "jichan shiren",
        "liaochan shiren",
        "mingchan shiren",
});
        
string ask_me()
{
        mapping my_fam, skl; 
       object fighter,me,room, monk;
        string *sname;
        int i,j;
        fighter = this_player();
        me = this_object();

        my_fam  = fighter->query("family");
        skl = fighter->query_skills();
        sname  = keys(skl);
        sname  = keys(skl); 
        
       if(!fighter->query_temp("try"))
          return "�������������?\n";
          for(i=0; i<sizeof(skl); i++) {
           if (skl[sname[i]] < 120) 
        return (RANK_D->query_respect(this_player()) +
                "�����������������ԡ�");
             } 
        if(fighter->query("passdu"))
         return (RANK_D->query_respect(fighter)+
                "��ʦ�������ϵļ��Ÿߵܣ��α�����������?\n");
        if( fighter->query("pass_xin") )
                return (RANK_D->query_respect(fighter) + 
                "�������ڸ�ɮ���ɲ�Ҫ�����Ŀ������Ц��");

        if ( (int)fighter->query("guilty") > 0 )
                return (RANK_D->query_respect(fighter) + 
                "���۷����䣬�����������Ȼ�ȥ��ڰɣ�\n");
        say("\n����˵�����ðɣ���������ʯ����أ�������þͻ���Ϊ��(huadi)׼������ɡ�\n");
        me->set("assigned_fighter", fighter->query("id"));              
        message_vision("\n�������߼����뿪��\n\n", fighter);
       for(j=1; j<8; j++) 
        { 
               if(!( room = find_object("/d/shaolin/shiting" + j)) )
                room = load_object("/d/shaolin/shiting" + j);
                me->move(room);
                if( !objectp(monk = present(names[j-1], room) ))
                {
                        me->move("/d/shaolin/xcping");
                        message_vision("\n�����������˹�����\n\n", fighter);
                        return "���ǶԲ���ʯͤ����ʯ�˶��ԣ�û�����д����ˡ�\n"; 
                }
                message("vision", "\n�����������˹�������" + monk->query("name") + "�������һ�ơ�\n", room, monk);
                monk->move("/d/shaolin/xctang");
                message("vision", monk->query("name") + "�첽���˳�ȥ��\n", room, monk);
        }

        me->move("/d/shaolin/xcping");
        call_out("waiting", 1, me);
        return ("�ã���Ҷ������ˡ�\n");
 
}

void waiting(object me)
{
        object fighter;
        int wait_time;

        if( wait_time == 300 )
        {
                say( "����˵��������������������ˣ�\n\n");
                call_out("do_back", 0, me);             
        }

        if( !objectp( fighter = present( me->query("assigned_fighter"), environment(me) ) ) )
        {
                wait_time++;
                call_out("waiting", 1, me);
        }
        else if(!fighter->query_temp("huadi") )
        {
                if( random(10) == 0 ) 
                say("\n����˵����" + RANK_D->query_respect(fighter) + "�㻯��Ϊ�����𣿿��ɣ�\n");

                wait_time++;
                call_out("waiting", 1, me);
        }
        else call_out("preparing", 1, me, fighter);

 
        return;
}

int preparing(object me, object fighter)
{
        object room;

//      if(!( room = find_object("/u/hunthu/xctang")) )//
//      room = load_object("/u/hunthu/xctang");
//      monk = present("mu ren", room);
//      monk->move("/d/shaolin/houdian");

        if(!( room = find_object("/d/shaolin/xcping")) )
        room = load_object("/d/shaolin/xcping");
//      monk = present("mu ren", room);
//      monk->move("/d/shaolin/houdian");

//      if(!( room = find_object("/d/shaolin/hguangz2")) )
//      room = load_object("/d/shaolin/hguangz2");

//      monk = present("daojue chanshi", room);
//      message("vision", "�����ʦ��������ʦ��������˵�˼��䡣\n", room, monk );
//      monk->move("/d/shaolin/houdian");
//      monk->move("/d/shaolin/houdian"); 
//      message("vision", monk->query("name") + "��ʦ���˵�ͷ���첽�����뿪��\n", room);

        message("vision", HIY "\n���ƴ�ʦ��������������ʯ�˴���������\n" NOR, room);
        message("vision", "\nֻ��һ��������죬�߸����ޱ����ʯ�˶�ס��ͨ·��\n\n", room);
        room->delete("exits");
        command("chat " + fighter->query("title") + fighter->query("name") + 
        "�ڽ���" + NATURE_D->game_time() + "��ս���������ϴ���\n");
       fighter->delete_temp("baitie");
        fighter->delete_temp("huadi");
        fighter->delete_temp("beat_count");
       fighter->set_temp("fighting", 1);
        call_out("fighting",  7, me, fighter, 0);
        return 1;
}

void fighting(object me, object fighter, int count)
{
        object monk1, monk2, room1, room2;
        if(!( room1 = find_object("/d/shaolin/xctang")) )
        room1 = load_object("/d/shaolin/xctang");
        if(!( room2 = find_object("/d/shaolin/xcping")) )
     room2 = load_object("/d/shaolin/xcping");
        //      message_vision(HIY "xuanku's count = " + count + "\n" NOR, fighter);
        //      message_vision(HIY "xuanku's count = " + count + "\n" NOR, fighter); 

if( count <= 7 ) {
                message("vision", "\nʯ�˸�̤�Ź����Է�λ������������\n" NOR, room2);

                monk1 = present(names[count], room1);
                if (monk1) monk1->move(room2);
        }
                
        if( count >= 1 && count <= 7 ) {
                monk2 = present(names[count-1], room2);
                if (monk2) monk2->move(room1);
        }

        if (!living(fighter) || environment(fighter)!=environment(me))
        {
                if( objectp(fighter)) {
                        fighter->delete_temp("fighting");
                        fighter->delete_temp("beat_count");
                }
                monk1->move(room1);

                say( "����ҡ��ҡͷ��˵������˵�������԰ɣ�\n\n");
                command("sigh");
                command("sigh"); 
              command("chat"+ "*"+ "disapp");
                call_out("do_back", 5, me );
        }
          else if( count >= 6 )
        {
                if( (int)fighter->query_temp("beat_count") >= 7 ) 
                        call_out("do_recruit", 5, me, fighter);
                else
                        call_out("do_back", 5, me );
        }
        else
        {
                count++;
                call_out("fighting", 2, me, fighter, count);
        }
 
        
}

int do_recruit(object me, object fighter)
{
object ob1;
        fighter->delete_temp("beat_count");
        fighter->delete_temp("beat_count"); 
        fighter->delete_temp("fighting");
        fighter->add("combat_exp", 30000);
        fighter->set("pass_xin", 1);
        //command("chat congra");       
        say("\n����˵������ϲ�㴳������������ �������ֶ�һ��ɮ��\n");
say("\n����˵��������һ�������ӣ�ϣ����������߹�����\n");
ob1=new("/clone/medicine/neili/puti-zi");
ob1->set("owner",fighter->query("id"));
ob1->move(fighter);
        call_out("do_back", 1, me );
        return 1;
        }
int do_back(object me)
{
        object monk, room1, room2;
        int i;

        message("vision", "\n���ƴ�ʦ�������أ� ʯ�����漴����뿪��\n", environment(me) );
        
        if(!( room1 = find_object("/d/shaolin/xctang")) )
        room1 = load_object("/d/shaolin/xctang");
 //       if(!( room2 = find_object("/d/shaolin/xcping")) )
 //       room2 = load_object("/d/shaolin/xcping");
 //       room2 = load_object("/d/shaolin/xcping"); 
//        monk = present("daojue chanshi", room2);
//      monk->move("/d/shaolin/hguangz2");
//        monk = present("mu ren", room2);
//      monk->move("/d/shaolin/wuchang2");
//        monk = present("mu ren", room2);
//      monk->move("/d/shaolin/wuchang1");

        if(!( room1 = find_object("/d/shaolin/xcping")) )
        room1 = load_object("/d/shaolin/xcping");
        room1->set("exits/north",  "/d/shaolin/xctang.c");
        room1->set("exits/west","/d/shaolin/fatang.c"); 
      if(!( room1 = find_object("/d/shaolin/xctang")) )
      room1 = load_object("/d/shaolin/xctang");
        for(i=1; i<8; i++) 
        {
                if(!( room2 = find_object("/d/shaolin/shiting" + i)) )
                room2 = load_object("/d/shaolin/shiting" + i);
                if( objectp( monk = present(names[i-1], room1) ))
                        monk->move(room2);
        }
        me->delete("assigned_fighter");
        me->move("/d/shaolin/xcping");
        return 1;
} 
void destroying(object me, object obj) 
{
       destruct(obj);
       return;
}

