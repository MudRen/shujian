// heiwu.c
// ����
inherit ROOM;
void create()
{
	set("short","����");
	set("long",@long
�����������̵��ӷ���ʱ�ܳͷ��ĵط�����������û��һ�ȴ��ӣ�Ҳû
���ţ�ֻ���ݶ����˸����ڣ�װ�˿鷭�塣�������հ������⣬�ȳ��˱ǣ�
�����������θ��޴�������ֻ�����ڵ��ϻ��(fu)ǽվ�š�����ֻ�г��Ļ�
��(repent)���˲��ܳ�ȥ��
long);
      //set("no_fight",1);
      set("valid_startroom", 1);      setup();
}

void init()
{        
     add_action("do_fu","fu");
     add_action("do_mo","mo");
     add_action("do_repent","repent");
     add_action("do_quit","quit");
}

int do_quit(string arg)
{
    object me=this_player();

    me->set("startroom","/d/sld/npc/obj/heiwu");    return 0; 
}

int do_fu(string arg)
{
    object me=this_player();
    //object ob=this_object();
    //int qi;

    if(!arg || (arg!="wall" && arg!="ǽ" && arg!="ǽ��"))
        return notify_fail("��Ҫ��ʲô��\n");
    if(random(10)>5)
    {
        tell_object(me,"�������ǽ�ڣ�����(mo)��ǽ�Ϻ������һЩ�֡�\n");
        me->set_temp("heiwu/mo",1);
    }
    else
        tell_object(me,"�������ǽ�ڡ�\n");
    return 1;
}

int do_mo(string arg)
{
    object me=this_player();
    int cost,i,j,my_skill;
    string zhao_name;
    string* skill= ({ "force","dodge","parry","strike","throwing","whip","shenlong-yaoli","poison" });
    int flag;

    if(!arg || (arg!="wall" && arg!="ǽ" && arg!="ǽ��") || (me->query_temp("heiwu/mo",1)!=1))
        return notify_fail("��Ҫ��ʲô��\n");
    if( !me->query_skill("literate", 1) )
        return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");              
    //if( me->query_int() < skill["difficulty"])
        //return notify_fail("����Ŀǰ��������������û�а취ѧ������ܡ�\n");
    i=random(sizeof(skill));
    j=i;
    flag=0;
    do
    {
        if(me->query_skill(skill[j], 1)!=0)
        {
            if( !SKILL_D(skill[j])->valid_learn(me) ) 
            {
                if(flag==0) flag=1;
            }
            else if( me->query_skill(skill[j], 1) > 49 )
                flag=2;
            else 
                break;
        }    
        j++;
        if(j>=sizeof(skill)) j=0;
        if(j==i)
        {
            if(flag!=2)
                return notify_fail("�����˰��죬���һ������\n");
            else
                return notify_fail("������һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
        }
    } while(1);
    //if( !SKILL_D(skill[j])->valid_learn(me) )
        //return notify_fail("�����˰��죬���һ������\n");     
    cost = 50-me->query_skill(skill[j],1)*(int)me->query_int()/20;
    if (cost < 10) cost = 10; // minimum cost
    //if( me->query_skill(skill[j], 1) > 49 )
        //return notify_fail("������һ��������Ƿ���������˵�Ķ�����Զ�̫ǳ�ˣ�û��ѧ���κζ�����\n");
    my_skill = me->query_skill(skill[j], 1);
    if( (int)me->query("jing") > cost ) {
        if( (string)SKILL_D(skill[j])->type()=="martial" &&
          my_skill * my_skill * my_skill / 10 > (int)me->query("combat_exp") ) 
        {
            printf("Ҳ����ȱ��ʵս���飬��������Ķ��������޷���ᡣ\n");
        } 
        else {
            if(zhao_name = SKILL_D(skill[j])->query_skill_name(my_skill))
                printf("�������й�%s�ļ��ɣ��ԡ�%s����һ���ƺ���Щ�ĵá�\n", 
                       to_chinese(skill[j]), zhao_name);
            else
                printf("�������й�%s�ļ��ɣ��ƺ��е��ĵá�\n", to_chinese(skill[j]));
            me->improve_skill(skill[j], 
            ((int)me->query_skill("literate", 1)/5+1)*me->query_kar()/20);
        }
        me->receive_damage("jing", cost );
    } 
    else {
                //cost = me->query("jing");
        write("�����ڹ���ƣ�룬�޷�ר�������ж���֪��\n");
    }
    return 1;
}

int do_repent(string arg)
{
    object me=this_player();

    if((time()-me->query("in_heiwu"))/60<15)
        return notify_fail("��ڹ���ʱ��̫�̡�\n");
    if(random(me->query_kar())==0)
    {
        me->set("in_heiwu",time()-840);
        return notify_fail("�㻹�������ġ�\n");
    }
    me->delete_temp("heiwu/mo");
    me->move("/d/sld/dt");
    me->set("startroom","/d/city/kedian");    return 1;   
}
    
