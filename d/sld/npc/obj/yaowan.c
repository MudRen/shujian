#include <ansi.h>

inherit ITEM;
inherit F_LIQUID;

void back_rq(object);
void eat_yao(object ob);

void init()
{
	add_action("do_eat", "eat");
        add_action("do_kan", "kan");
        add_action("do_mo", "mo");
        add_action("do_rong", "rong");
        add_action("do_drink", "drink");
        add_action("do_throw", "throw");
}

void create()
{
        set_name(HIG "��ҩ" NOR, ({"danyao","yao","dan"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                "����һ�������̶������Ƶĵ�ҩ��\n");
                set("unit", "��");
                set("t_unit","��");
                set("no_sell",1);
        }
}

int do_kan(string arg)
{
        object me=this_player();
        object yao=this_object();
        string* type=({"��","��","��","ˮ","ľ"});
        string* use=({"������","��ʳˮ","����","����","������"});//ҩ������
        int i,j,max,types;
        string msg;

        if((me->query_skill("poison",1)<120) || (me->query_skill("shenlong-yaoli",1)<120))
                return 0; 
        if(yao->query("poison")=="ȫ")
        {
                msg=sprintf("����һ%s�ⶾ��ҩ���ɽ�%d�ζ���\n",yao->query("t_unit"),yao->query("zycs"));
                tell_object(me,msg);
        }
        else
        {
                types=yao->query("types");
                for(i=0;i<sizeof(type);i++) 
                {
                        if(yao->query("poison")==type[i])
                        {
                                if(types==1)
                                {
	msg=sprintf("����һ%s��ҩ��������%s�����ɶ���%d�Ρ�\n",yao->query("t_unit"),type[i],yao->query("zycs"));
                                }
                                else
                                {
	                                msg=sprintf("����һ%s��ҩ��������%s�����ɶ���%d�Σ����⻹������һЩ\n",yao->query("t_unit"),type[i],yao->query("zycs"));
                                        for(j=0;j<sizeof(type);j++)
                                        {
                                                if(j==i)
                                                        continue;
                                                else if(yao->query(type[j])==0)
                                                        continue;
                                                else
                                                {
                                                        msg=sprintf("%s%s(+%d)",msg,use[j],yao->query(type[j]));
                                                }
                                        }
                                        msg+="��ҩ�\n";
                                }
                                tell_object(me,msg);
                                break;
                        }
                }
                if(i>=sizeof(type))
                {
                        if(types>0)
{
                                max=0;j=0;
                                msg="����һ"+yao->query("t_unit")+"��ҩ������";
                                for(i=0;i<sizeof(type);i++) 
                                {
                                        if(yao->query(type[i])==0)
                                                continue;
                                        msg=sprintf("%s%s(+%d)",msg,use[i],yao->query(type[i]));
                                        if(yao->query(type[i])>max)
                                        {
                                                max=yao->query(type[i]);
                                                j=i;
                                        }
                                }
                                msg=msg+"��ҩ�������"+use[j]+"��ҩ��Ϊ����\n";
                                tell_object(me,msg);
                        }
                        else
                        {
                                tell_object(me,"����һ"+yao->query("t_unit")+"ƭ���õļ�ҩ��\n");
                        }       
                }
        }
        tell_object(me,"����Զ��俴(kan)��ĥ(mo)������(throw XXX)��\n");
        return 1;
}

int do_mo(string arg)
{
        object yao=this_object();
        object me=this_player();

        if(yao->query("t_unit")=="��")
        {
                yao->set("t_unit","��");
                yao->set("nums",100);
                tell_object(me,"���"+yao->name(1)+"ĥ���˷�ĩ��\n");
        }
        else
                tell_object(me,yao->name(1)+"�Ѿ�����ĥ�ˡ�\n");
        return 1;
}

int do_drink(string arg)
{
        int jl;
        if( !this_object()->id(arg) || !living(this_player())) return 0;
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");
/*
        if( this_object()->query("t_unit")!="��")
                return 0;
*/
        if( !query("liquid/remaining") )
                return notify_fail( name() + (query("liquid/name") ? "�Ѿ����ȵ�һ��Ҳ��ʣ�ˡ�\n":"�ǿյġ�\n"));
        if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
                return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");
        jl=((this_player()->query("pur",)*random(20))+(random(this_player()->query("per",)*10)));
        //add("liquid/remaining", -1);
        message_vision("$N����" + name() + "������غ��˼���" + query("liquid/name")
+ "��\n", this_player());
//        this_player()->add("combat_exp",jl);
        this_player()->add("water", 5*query("liquid/remaining"));
        if( this_player()->is_fighting() ) this_player()->start_busy(2);
        if( !query("liquid/remaining") )
                write("���Ѿ���" + name() + "���" + query("liquid/name")
                        + "�ȵ�һ��Ҳ��ʣ�ˡ�\n");
        eat_yao(this_player());
        if(this_object()->query("nums")<=0)
        {
                set("liquid/type", "water");
                set("liquid/name", "��ˮ");
                set("liquid/remaining", 0);
                // This allows customization of drinking effect.
                if( query("liquid/drink_func") )
                {
                        call_out("back_rq", 1, this_player());
                        return 1;
                }
                switch(query("liquid/type")) {
                        case "alcohol":
                                this_player()->apply_condition("drunk",
                                (int)this_player()->query_condition("drunk") 
                                + (int)query("liquid/drunk_apply"));
                                break;
                }

                call_out("back_rq", 1, this_player());
        }       
        return 1;
}

int do_fill(string arg)
{
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");
        if( this_object()->query("t_unit")!="��")
                return 0;
        if( !environment(this_player())->query("resource/water") )
                return notify_fail("����û�еط�����װˮ��\n");

        if( query("liquid/remaining") )
                message_vision("$N��" + name() + "��ʣ�µ�" + query("liquid/name") + "������\n", this_player());
        message_vision("$N��" + name() + "װ����ˮ��\n", this_player());

        if( this_player()->is_fighting() ) this_player()->start_busy(2);
        
        set("liquid/type", "water");
        set("liquid/name", "��ˮ");
        set("liquid/remaining", query("max_liquid"));
        set("liquid/drink_func", 0);
        call_out("back_rq", 1, this_player());
        return 1;
}

void back_rq(object ob)
{
        object rq;

	if(!objectp(rq=new(query("old")))) tell_object(this_player(),name()+"���ٻ��ˡ�\n");
        else {
                rq->set("liquid", query("liquid"));
                rq->move(ob);        
        }
        destruct(this_object());
}

int do_rong(string arg)
{
        object rq;
        object me=this_player();
        object ob=this_object();

        if(!objectp(rq=present(arg, me))&&!objectp(rq=present(arg, environment(me))))
                return notify_fail("��Ҫ��"+ob->query("name")+"���ںδ���\n");
        if(rq->query("liquid")==0)
                return notify_fail(arg+"�������ܻ������ġ�\n");
        if( !rq->query("liquid/remaining") )
                return notify_fail( rq->name()+"�����ǿյģ������ܻ��κζ�����\n");
        if(rq->query("t_unit")!=0)
                return notify_fail( rq->name()+"���Ѿ�����ҩ���ˡ�\n");
        if(ob->query("t_unit")!="��")
        {
                ob->set("t_unit","��");
tell_object(me,"���"+ob->name()+"����"+rq->name()+"�У����˽�����һ�ᣬ���ܻ��������ˡ�\n");
        }
        else
                return notify_fail( ob->name()+"���Ѿ�����ҩ���ˡ�\n");
        ob->set_name(rq->query("name"),rq->parse_command_id_list());
        ob->set_weight(rq->query_weight());
        ob->set("long", rq->query("long"));
        ob->set("unit", rq->query("unit"));
        ob->set("value", rq->query("unit"));
        ob->set("max_liquid", rq->query("max_liquid"));
        ob->set("liquid", rq->query("liquid"));
        ob->set("liquid/remaining",rq->query("liquid/remaining"));
        ob->set("old",base_name(rq));
        destruct(rq);
        return 1;
}

int do_eat(string arg)
{
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");
        if( this_object()->query("t_unit")=="��")
                return 0;
        message_vision("$N��"+name()+"һ��������ȥ��\n",this_player()); 
        eat_yao(this_player());
        if(this_object()->query("nums")<=0)
        {
                destruct(this_object());
}
        return 1;
}

int do_throw(string arg)
{
        object target,room;
        object me=this_player();
        int yq;

        if( !this_object()->id(arg) ) return 0;
        if( me->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");
        if(( this_object()->query("t_unit")!="��") || ( !this_object()->query("poison")) 
          || (this_object()->query("poison")=="ȫ"))
                return notify_fail("��ֻ���������ۡ�\n");
        if(!objectp(target=present(arg, environment(me))) || !living(target) || target->is_ghost())
                return notify_fail("��Ҫ��˭�������ۣ�\n");
        if(objectp(room=environment(me)))
        {
                if(room->query("no_fight")==1)
                        return notify_fail("�㲻���������������ۡ�\n");
        }
        message_vision("$N��"+name()+"��$n������ȥ��\n",me,target);
        if((yq=random(me->query("combat_exp")*100/target->query("combat_exp"))+random(me->query_dex()*100/target->query_dex())
          +random(me->query_kar()*100/target->query_kar()))>=300)
        {
message_vision("$n����������������������"+name()+"���������ǣ�\n",me,target);
                eat_yao(target);        
        }
        else if((yq<=100) && (target->query_skill("force")>=300) && (target->query("neili")>=350))
        {
                message_vision("$n���Ų�æ���������������Ķ����͵�һ�������$N����������������������"+name()+"���������ǣ�\n",me,target);
                eat_yao(me);
                target->add("neili",-300);      
        }
        else
                message_vision("$nһ��������������"+name()+"���������\n",me,target); 
        me->start_busy(random(2)+1);
        if(!target->if_fighting(me))
        {
                target->fight_ob(me);
                me->fight_ob(target);
        }
        if(this_object()->query("nums")<=0)
                destruct(this_object());
        return 1;
}

void eat_yao(object ob)
{
        //object du;
        //mixed* files;
        //string dir,fn;
int i,cs,zycs,num,num2,faint;
        string dutype1; 
        string * dus=({"bee_poison","bing_poison","bt_poison","chanchu_poison","cold_poison","dsy_poison","fs_poison",
                       "hb_poison","hot_poison","huagu_poison","juehu_hurt","man_poison","qianzhu_poison","qinghua_poison",
                       "qishang_poison","qtlh_poi","sanxiao","scorpion_poison","sl_poison","slumber_drug","snake_poison",
                       "wh_poison","xx_poison","yysan_poison"});
        string * dun=({"��䶾","�������붾","���չ��߶�","��ܾ綾","����","����ӡ��","��ʬ��","�������ƶ�","�ȶ�",
                       "�������ƶ�","�����綾","�����ܻ���","ǧ�����ֶ�","�黨��","����ȭ��","�����޻���","��Ц���궾",
                       "Ы��","���������","�ɺ�ҩ��","�߶�","�������ж�","�����ƶ�","����ҩ��"});
        string * dutype=({"��","ľ","��","ˮ","��","��","ľ","��","ˮ","��"});

        if(query("poison")=="ȫ")
        {
                if(this_object()->query("nums")>0)
                {
                        zycs=query("zycs")/5;
                        this_object()->add("nums",-20);
                }
                else
zycs=query("zycs");
                for(i=0;i<sizeof(dus);i++)
                {
                        if((cs=ob->query_condition(dus[i],1))>0)
                        {
                                if(zycs>cs)
                                {
                                        ob->apply_condition(dus[i],0);
                                        zycs=zycs-cs;
                                        tell_object(ob,"���"+dun[i]+"�������ˡ�\n");
                                }
                                else
                                {
                                        cs=cs-zycs;
                                        ob->apply_condition(dus[i],cs);
                                        tell_object(ob,"���"+dun[i]+"��������һ���֡�\n");
                                        break;
                                }
                        }
                }
                if((zycs>=150) && (ob->query_skill("shenlong-yaoli",1)<150))
                {
                        i=random(sizeof(dus));
                        ob->apply_condition(dus[i],ob->query_condition(dus[i],1)+zycs);
                        tell_object(ob,"����"+name()+"�Ķ������ù�ǿ��������"+dun[i]+"��\n");
                }
                else if((zycs>=50) && (ob->query_skill("shenlong-yaoli",1)<200) && (ob->query_skill("poison",1)<200))
                {
                        tell_object(ob,"����"+name()+"�Ķ������ù�ǿ���������ش���\n");
ob->receive_damage("qi", zycs*2);
                        ob->receive_wound("qi", zycs);
                }
                return;
        }
        if(query("poison")!=0)
        {
                if(this_object()->query("nums")>0)
                {
                        zycs=query("zycs")/5;
                        this_object()->add("nums",-20);
                }
                else
                        zycs=query("zycs");
                cs=ob->query_condition("wh_poison",1);
                dutype1=ob->query("poisontype");
                if(!dutype1 || (dutype1==query("poison")) || (cs==0))
                {
                        ob->apply_condition("wh_poison",cs+zycs);
                        ob->set("poisontype",query("poison"));
                        tell_object(ob,"��������������"+query("poison")+"����\n");
                }
                else
                {
                        for(i=0;i<sizeof(dutype);i++)
                        {
                                if(dutype[i]==query("poison"))
                                        break;
                        }
                        if((dutype1==dutype[i+1]) || (dutype1==dutype[i+4]))
{
                                if(zycs>cs)
                                {
                                        zycs=zycs-cs;
                                        ob->apply_condition("wh_poison",zycs);
                                        ob->set("poisontype",query("poison"));
                                        tell_object(ob,"��������������"+query("poison")+"����\n");
                                }
                                else if(cs>zycs)
                                {
                                        cs=cs-zycs;
                                        ob->apply_condition("wh_poison",cs);
                                        tell_object(ob,"���ڶ�����ˣ������е���������"+dutype1+"���������˲��֣�\n");
                                }
                                else 
                                {
                                        ob->apply_condition("wh_poison",0);
                                        ob->delete("poisontype");
                                        tell_object(ob,"���ڶ�����ˣ������е���������"+dutype1+"���������ˣ�\n");
                                }
                        }
                        else if(dutype1==dutype[i+2])
                        {
                                ob->apply_condition("wh_poison",zycs+cs*2);
                                ob->set("poisontype",query("poison"));
                                tell_object(ob,"��������������"+query("poison")+"����\n");
                        }
else if(dutype1==dutype[i+3])
                        {
                                ob->apply_condition("wh_poison",cs+zycs*2);
                                tell_object(ob,"���ڶ��������������е���������"+dutype1+"�������ˣ�\n");
                        }
                }
        }
        faint=0;
        if(query("��")!=0)
        {
                if(ob->query_temp("maxjing",1)==0)
                        ob->set_temp("maxjing",ob->query("max_jing"));
                if(this_object()->query("nums")>0)
                {
                        num=ob->query("eff_jing")+query("��")/5;
                        this_object()->add("nums",-20);
                }
                else
                        num=ob->query("eff_jing")+query("��");
                if(num>(ob->query_temp("maxjing",1)*2))
                {
                        tell_object(ob,"��ͻȻ�е�һ�ɼ�ǿ���������¸���ֱ��ͷ�������󱻻��Ƶأ�\n");
                        ob->receive_damage("jing",ob->query("jing"));
                        ob->receive_wound("jing", ob->query("eff_jing")/2);
                        faint=1;
                }
                else
                {
tell_object(ob,"��е�һ��ů�����¸�����ͷ����ȥ��������ˡ�\n"); 
                        if(num>ob->query("max_jing"))
                        {
                                if(num>(ob->query_temp("maxjing",1)+ob->query_temp("maxjing",1)/4))
                                        num=ob->query_temp("maxjing",1)+ob->query_temp("maxjing",1)/4;
                                ob->set("max_jing",num);
                        }
                        ob->set("eff_jing",num);
                }
        }
        if(query("��")!=0)
        {
                if(this_object()->query("nums")>0)
                {
                        num=ob->query("food")+query("��")/10;
                        num2=ob->query("water")+query("��")/10;
                        this_object()->add("nums",-20);
                }
                else
                {
                        num=ob->query("food")+query("��")/2;
                        num2=ob->query("water")+query("��")/2;
                }
                if((num>(ob->max_food_capacity()*3)) || 
                   (num2>(ob->max_water_capacity()*3)))
                {
                        tell_object(ob,"���������ڳԺȹ����ˣ������ǵú����ܣ�\n");
ob->receive_damage("qi",ob->query("qi")/2);
                        ob->receive_damage("jing", ob->query("jing")/2);
                        ob->set("food",ob->max_food_capacity());
                        ob->set("water",ob->max_water_capacity());
                        ob->start_busy(random(3)+3);
                }
                else
                {
                        tell_object(ob,"��е����ӱ��˲��٣�����Ҳ������ˡ�\n"); 
                        ob->set("food",num);
                        ob->set("water",num2);
                }
        }
        if(query("ˮ")!=0)
        {
                if(ob->query_temp("maxqi",1)==0)
                        ob->set_temp("maxqi",ob->query("max_qi"));
                if(this_object()->query("nums")>0)
                {
                        num=ob->query("eff_qi")+query("ˮ")/5;
                        this_object()->add("nums",-20);
                }
                else
                {
                        num=ob->query("eff_qi")+query("ˮ");
                }
                if(num>(ob->query_temp("maxqi",1)*2))
                {
                        tell_object(ob,"��ͻȻ�е�ȫ����Ѫ�������������֮����\n");
                        ob->receive_damage("qi",ob->query("qi"));
ob->receive_wound("qi", ob->query("eff_qi")/2);
                        faint=1;
                }
                else
                {
                        tell_object(ob,"��е����ϵ����ƺ��˺ܶࡣ\n"); 
                        if(num>ob->query("max_qi"))
                        {
                                if(num>(ob->query_temp("maxqi",1)+ob->query_temp("maxqi",1)/4))
                                        num=ob->query_temp("maxqi",1)+ob->query_temp("maxqi",1)/4;
                                ob->set("max_qi",num);
                        }
                        ob->set("eff_qi",num);
                }
        }
        if(query("��")!=0)
        {
                if(this_object()->query("nums")>0)
                {
                        num=ob->query("neili")+query("��")/5;
                        this_object()->add("nums",-20);
                }
                else
                {
                        num=ob->query("neili")+query("��");
                }
                if(num>=(ob->query("max_neili")*7/2))
                {
                        tell_object(ob,"��ͻȻ�е�������������֮�����������������ͻ��\n");
ob->receive_damage("qi",ob->query("qi")*3/4);
                        ob->receive_damage("jing", ob->query("jing")*3/4);
                        ob->set("neili",0);
                        faint=1;
                }
                else if(num>ob->query("max_neili"))
                {
                        tell_object(ob,"��е�����ȫ���ָ��ˡ�\n");
                        ob->set("neili",ob->query("max_neili"));
                }
                else
                {
                        tell_object(ob,"��е������ָ����١�\n");
                        ob->set("neili",num);
                }
        }
        if(query("ľ")!=0)
        {
                if(this_object()->query("nums")>0)
                {
                        num=ob->query("jingli")+query("ľ")/5;
                        this_object()->add("nums",-20);
                }
                else
                {
                        num=ob->query("jingli")+query("ľ");
                }
                if(num>=(ob->query("eff_jingli")*7/2))
                {
                        tell_object(ob,"��е�������ʢ֮�������ɵ�ƴ����й��������ֹ��\n");
ob->receive_damage("qi",ob->query("qi")*3/4);
                        ob->receive_damage("jing", ob->query("jing")*3/4);
                        ob->set("jingli",0);
                        faint=1;
                }
                else if(num>ob->query("eff_jingli"))
                {
                        tell_object(ob,"��е�����ȫ���ָ��ˡ�\n");
                        ob->set("jingli",ob->query("eff_jingli"));
                        if((time()-ob->query("jl_add"))>3600)
                        {
                                ob->set("old_maxjl",ob->query("max_jingli"));
                                ob->set("old_effjl",ob->query("eff_jingli"));
                                ob->add("eff_jingli",num/ob->query("eff_jingli")); 
                                ob->add("max_jingli",num/ob->query("eff_jingli")); 
                                ob->set("jl_add",time());
                        }
                        else
                        {
                                ob->add("max_jingli",num/ob->query("eff_jingli")); 
                                ob->add("eff_jingli",num/ob->query("eff_jingli")); 
                                if((ob->query("max_jingli")-ob->query("old_maxjl"))>3)
                                {
                                        ob->set("max_jingli",ob->query("old_maxjl")+3);
                                        ob->set("eff_jingli",ob->query("old_effjl")+3);
                                }
                        }
                }
                else
{
                        tell_object(ob,"��е������ָ����١�\n");
                        ob->set("jingli",num);
                }
        }
        if(faint)
                ob->unconcious();
}

