// jingzuo.h

void init()
{
   add_action("do_action", ({"dazuo", "tuna", "learn", "du", "study", "xue", }));
       add_action("do_halt", "halt");
       add_action("do_lian", "lian");
       add_action("do_lian", "practice");
       add_action("do_jingzuo", "jingzuo");
}
int do_action(string arg)
{
   write("�����������������뾲���޹ص����飡\n");
   return 1;
}
int do_lian()
{
       object me = this_player();
        if(environment(me) && me->query_temp("jingzuo")) { 
       write("����æ���ء�\n", me);
       return 1; }
}
int do_jingzuo(string arg)
{
        object me;
        int lvl;     
        me = this_player();
        lvl = (int)me->query_skill("dacheng-fofa", 1);

       if( me->query("family/family_name") != "������" || me->query("class") != "bonze" )
        return notify_fail("���Ƕ����ɷ��ŵ���������Ϲ��ʲô�ң�\n");

        if( lvl < 30 )
        return notify_fail("���˷�δ����򣬲��ܾ���������\n");

        if( me->query("combat_exp") > 300000 )
        return notify_fail("�������ڵ���Ϊ���Ѿ�����ͨ�����������ˡ�\n");

        if (me->is_busy() || me->is_fighting())
        return notify_fail("����æ���ģ�\n");

        if (me->query_temp("jingzuo"))
        return notify_fail("�����ھ����С�\n");

       if((int)me->query("jingli", 1) < 30 )
       return notify_fail("��̫���ˣ����Ǻú���Ϣ�ɡ�\n");
       
       if(random(10) < 4 ) {
       switch(random(5) ) {
       case 0: {
       write("��Ȼ���洫��һ������������ֻ���ķ����ң����ܾ���������
              ֻ�ø�ȥ���������������С�\n", me); 
       me->move(__DIR__"chanfang3"); }  
       break;

       case 1: { 
       write("��Ȼ���洫��һ������������ֻ���ķ����ң����ܾ���������
               ֻ�ø�ȥ���������������С�\n", me);
       me->move(__DIR__"chanfang2"); }
       break;
       
       case 2: { 
       write("��Ȼ���洫��һ������������ֻ���ķ����ң����ܾ���������
               ֻ�ø�ȥ���������������С�\n", me);
       me->move(__DIR__"chanfang"); }
       break;

       case 3: { 
       write("��Ȼ���洫��һ������������ֻ���ķ����ң����ܾ���������
               ֻ�ø�ȥ���������������С�\n", me);
       me->move(__DIR__"huazangancf"); }
       break; 

       case 4: { 
       write("��Ȼ���洫��һ������������ֻ���ķ����ң����ܾ���������
               ֻ�ø�ȥ���������������С�\n", me);
       me->move(__DIR__"baoguosicf"); }
       break; 
       } return 1;
     }
       else {
        message_vision(HIW"$N�ֳ�������������飬�Ȳ�ͷ����һ�ᣬȻ���ڵ��������������������ȡ�\n"NOR, me);
        me->set_temp("jingzuo", 1);
        call_out("do_wait", 20, me);
        return 1;  }
}

void do_wait()
{
        object me = this_player();
        if(environment(me) && me->query_temp("jingzuo")){
        write(GRN"
����ã������Ȼ��Ȼ�������ۣ���������˯�ţ�����˼·ʮ�������
��ֻ�������������Źֵ�����������Щ�Źֵ�������ȫ���������Լ�
����֮�ڵģ����������������������������Ĺ������������ڣ���ѪҺ
��������������Ҳ���Ըо��ó���������˵�������Լ�����ѪҺ����
����������Ϊ��ʵ�ڲ����ܣ�����ȴ��ʵʵ���ڣ���Ѫ�����������ĸ�
�� �� \n"NOR);          
          me->disable_player("<������>");
//    me->set("disable_type","<������>")
          call_out("do_wait1", 15, me);       
          }
}

void do_wait1()
{
        object me = this_player();
        if(environment(me) && me->query_temp("jingzuo")){
        write(CYN"
�������Լ�������֮�ڣ�������ô�����������ͬʱ�������أ�������
һ��ʮ������ĸо������ָо���������ǰ��δ���ģ�����Ҳʮ������
���ݡ����������������Ƿ��������������������ǲ�֪��ʲô�������
������Ѫ����������������һ����Ϫ�����岻Զ����������������������
����СϪ��ʯ�ϣ�������Ⱥ�����С�����
\n"NOR);
          me->disable_player("<������>");
          call_out("do_wait2", 15, me);       
          }
}

void do_wait2()
{
        object me = this_player();
        if(environment(me) && me->query_temp("jingzuo")){
        write(BLU"
����һ�ᣬ������ת����һ�£���֪��������ʲôԭ�����Ȼ�뵽��
��ɽ��ѩ���ڻ������ǣ�һ���ӣ������������������������뵽�ķ羰
������ˣ����˵�ѩ�������һ�ɹɵ�ˮ�������ʣ���ʱ�������ң���
�������������δ���������������ɣ�������Ҳ����СϪ�ߵ���磬��
���ӹ�ɽ�ҵľ��硣 
\n"NOR);
          me->disable_player("<������>");
          call_out("do_wait3", 15, me);       
          }
}

void do_wait3()
{
        object me = this_player();
        if(environment(me) && me->query_temp("jingzuo")){
        write(RED"
�������������ڵ���������Ϊ����Ȼ����������һ�����������������ˣ�
��������Щ��������Χ��������������Щ�������γɵĻ���֮�С����ң�
��������ǣ�����������ȫȻ�����Լ���������ı䣬һ��������Ϫ֮
�ԣ�һ�����ڸ�ɽ֮�ۣ�һ�������ڴ�֮������ֱ��ǧ���򻯣�����
���������ڵ���������ĸо����������Ѿ��뿪���Լ������壬������
�����Ȼ���޵ر�󣬶��˵�˼�룬���ڱ���˵�����֮�ڻһ���� 
\n"NOR);
//          me->clear_condition();
          me->disable_player("<������>");
          call_out("do_wait4", 15, me);       
          }
}

int do_wait4()
{      
       int lvl,gps;     
        object me = this_player();
       lvl = (int)me->query_skill("dacheng-fofa", 1);
        if(environment(me) && me->query_temp("jingzuo")){
        write(HIW"
��֪���˶�ã������ڸо����������ȫ���עȥ������ָо�����
��Ȼ��ȴ��ʱ�䡣����
��Ȼһ���𶯣���������һ�������˻����������뿪��������㣬
�ֻص�������֮��һ��������������ʱ�����������������Լ�������
Բ����ʯ���ڣ�Ҳ��ά�������ȶ��������ơ�  
\n"NOR);
message_vision(HIY"$N�Ѿ��ʹ���Ȼ��Ϊһ�壬����Ƭ�̣������ӵ�վ��������\n"NOR, this_player());
          me->delete_temp("jingzuo");               
            gps=(random(lvl/8)+20);
         if( ((int)me->query("potential", 1) + gps) > (int)me->query("max_pot", 1) ) {
         me->set("potential", (int)me->query("max_pot", 1));
         return 1;
        }
         me->add("potential", gps);
         return 1;
        }
       return 0;
}

int do_halt()
{
        object me = this_player();
        if(environment(me) && me->query_temp("jingzuo")) { 
       message_vision(HIY"$N�Ѿ�����ƣ�룬���������ϵĻҳ���վ��������\n"NOR, me);
       remove_call_out("do_wait");
       remove_call_out("do_wait1");
       remove_call_out("do_wait2");
       remove_call_out("do_wait3");
       remove_call_out("do_wait4");
       me->receive_damage("jingli", 20);
        me->delete_temp("jingzuo");               
       return 1;
          }
         else return 0;
} 
int valid_leave(object me, string dir)
{
       if(environment(me) && me->query_temp("jingzuo")) 
       return notify_fail("����æ���ء�\n");
       return ::valid_leave(me, dir);
}

