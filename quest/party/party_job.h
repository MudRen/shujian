
int do_sign(string arg)
{
   mapping fam;
   int i,j ;
   object *list;   
   object me, where, ling, target; 
   string *ah,word; 
   me = this_player();

 
if(!arg )       
       return notify_fail("����ſ����Ȼ���һ���Աߵ��˶�Ī������Ŀ����㡣\n");

if(arg =="fail"&& me->query_temp("party_job")) {
     ling = present("shimen mixin", me);
     if( ling && ling->query("party_job") == me->query("id"))
            destruct(ling);
    
      me->delete_temp("party_job");
      me->delete_temp("party_job_target");
      me->delete_temp("party_job_start");
      me->delete_temp("party_job_over"); //��������Ҫ����ģ�����ǳ������������Ƿ�����ʱ�����ҲҪ����
      me->apply_condition("job_busy", 3+random(4));
      me->add("combat_exp", -(240+random(130)));
message_vision(HIC"$N΢΢���˸����ƣ������Աߵ�С���������ҡ��ҡͷ��\n"NOR,me);
      return 1;  

                 }
//�����ɾ�����ܿ��ؿ��ưɡ�



if(arg =="start"){
	
        fam= me->query("family");
    if ( !fam )    
      	   return notify_fail("����ſ����Ȼ���һ���Աߵ��˶�Ī������Ŀ����㡣\n");
    if ( me->query_condition("killer"))
          return notify_fail("�������ǹٸ�׽�õ�Ҫ��������С��Ϊ�\n");
    if (me->query("job_name") == "ʦ�Ź���"|| me->query_temp("party_job"))            
    	   return notify_fail("���С������˸����ƣ�ȴ��ɥ�ķ�������æ���к������أ�û�����㡣\n");
    if ( me->query_condition("job_busy"))
    	   return notify_fail("���С������˸����ƣ�ȴ��ɥ�ķ�������æ���к������أ�û�����㡣\n");


if( fam["family_name"] =="������" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="������" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="��ɽ��" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="��ɽ��" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="������" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="������" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="�䵱��" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="�䵱��" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="������" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="������" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="������" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="������" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="����Ľ��" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="����Ľ��" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="������" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="������" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="ȫ���" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="ȫ���" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="�������" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="�������" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="�һ���" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="�һ���" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="������" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="������" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="���ư�" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="���ư�" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="������" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="������" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="ؤ��" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="ؤ��" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="��ɽ��" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="��ɽ��" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="��ң��" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="��ң��" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

if( fam["family_name"] =="���չ�" )
        list = filter_array(livings(),(:!userp($1) && ( $1->query("family/family_name") =="���չ�" ) && (!$1->query("no_party_job")) && (!$1->query_temp("party_job_target")) :));

  if (!j= sizeof(list) )   return notify_fail(HIG"���С������˸����ƣ�С���翴����һ�ۣ������ҡ��ҡͷ��\n"NOR);

        target = list[random(sizeof(list))];
     
        where = environment(target);
        me->apply_condition("job_busy",15);


        where = environment(target);
        target->set_temp("party_job_target",me->query("id") ); 
        target->apply_condition("clear_party_job",12);
        me->set_temp("party_job_target",target->query("name") ); 
        me->set_temp("party_job",target->query("id") ); 



//����ɴ���ling���������ˣ������������ݡ�
//��ͬ�������clone��ͬ��ling�������
//�����Ǻ�״̬Ҳһ���޸��ˡ����ڼ���
//npc��������Ҫɸѡ�����ھ�����δ���$1->query���ܸ�ֵ�������ˡ�



switch( random(3) ) {
 case 0: {
        ling  = new("quest/party/mixin");

        tell_object(me, "���С�����˸�����,С����ɫһ����Ҳ���ĵĸ�����˸����ơ�\n");
        tell_object(me, "С���ñ��˲�ע�⣬͵͵������һ�����š�\n");
        tell_object(me, HIG"����"+HIR+target->query("name")+HIW+"("+target->query("id")+")"+HIG"��"+HIC+where->query("short")+HIG+"�����գ����ٳ�Ԯ����������\n");
          }
                break;

 case 1: {
       ling  = new("quest/party/mixin");

       tell_object(me, "���С�����˸�����,С����ɫһ����Ҳ���ĵĸ�����˸����ơ�\n");
       tell_object(me, "С���ñ��˲�ע�⣬͵͵������һ�����š�\n");
       tell_object(me, HIG"������"+HIR+target->query("name")+HIW+"("+target->query("id")+")"+HIG"����й��ᣬ����ʦ�Ų�������ȥ"+HIC+where->query("short")+HIG+"������֮��\n"NOR);
       tell_object(me, HIR"�����춯����ɱ���ۣ�\n"NOR);
         }
                break;



 case 2: {
        ling  = new("quest/party/mixin");

        tell_object(me, "���С�����˸�����,С����ɫһ����Ҳ���ĵĸ�����˸����ơ�\n");
        tell_object(me, "С���ñ��˲�ע�⣬͵͵������һ�����š�\n");
        tell_object(me, HIG"���ɡ�"+HIR+target->query("name")+HIW+"("+target->query("id")+")"+HIG"���н�����Ϣ�ر�ʦ�ţ���ȥ"+HIC+where->query("short")+HIG+"����Ӧ��\n"NOR);
         }
                break;
                             }

        ling  ->set("party_job_target",target->query("id"));
        ling ->set("party_job",me->query("id"));   //���Ҳ��Ϊ��ʧ�ܵ�ʱ����������񵽱��˵���������Ҳ�п��ܵġ�
        ling ->move(me);

return 1;
}
else 
       return notify_fail("����ſ����Ȼ���һ���Աߵ��˶�Ī������Ŀ����㡣\n");
}