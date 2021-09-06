// yaolu.c

#include <ansi.h>

inherit ITEM;

#define MAXS 2160

void yao_id(string arg,object yao);
void yao_name(string arg,object yao);
void yao_long(string arg,object yao);

void init()
{
        add_action("do_fang", "fang");
        add_action("do_kan", "kan");
        add_action("do_qu", "qu");
        add_action("do_quyao", "quyao");
        add_action("do_get","get");
        add_action("do_put","put");
}

void create()
{
        set_name(HIG "ҩ¯" NOR, ({"yao lu","lu"}));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long",
                "����һֻ������ҩ��¯�ӣ������������(fang)ҩ�ģ�ȡ(qu)ҩ�ģ���(kan)¯�ӣ�ȡ(quyao)ҩ��\n");
                set("unit", "ֻ");
                set("no_sell",1);
                set("yaocai",0);
                set("zhuyao",0);
                set("location",1);
                call_out("qiangjie",600);
        }
}

void qiangjie()
{
        object ob=this_object();
        object me,xm;
        
        if(!ob)
                return;
        me=ob->query("owner");
        if(!me)
        {
                call_out("destructing", 1, ob); 
                return;
        }
        if(objectp(xm=me->query("rumo")))
                destruct(xm);
        xm=new("/d/sld/npc/xinmo");
        if(!objectp(xm))
        {
                me->delete("rumo");
                call_out("qiangjie",60);
                return;
        }
        xm->set("combat_exp",me->query("combat_exp")+me->query("combat_exp")/5);
        xm->set("str", me->query_str());
        xm->set("int", me->query_int());
        xm->set("con", me->query_con());
        xm->set("dex", me->query_dex()+me->query_dex()/3);
        xm->set("kar", me->query_kar());
        xm->set("max_qi",me->query("max_qi")+me->query("max_qi")/2);
        xm->set("qi",xm->query("max_qi"));
        xm->set("max_jing",me->query("max_jing")+me->query("max_jing")/2);
        xm->set("jing",xm->query("max_jing"));
        xm->set("max_neili",me->query("max_neili"));
        xm->set("neili",xm->query("max_neili")*2);
        xm->set("eff_jingli",me->query("eff_jingli")+me->query("eff_jingli")/3);
        xm->set("jingli",xm->query("eff_jingli")*2);
        xm->set_skill("dodge", me->query_skill("dodge",1)/2+me->query_skill("dodge"));
        xm->set_skill("parry", me->query_skill("parry",1)/2+me->query_skill("parry"));
        xm->set("name",me->name(1));
        xm->set("id",me->query("id"));
xm->set("long",me->query("long"));
        xm->set("gender",me->query("gender"));
        xm->set("title", me->query("title"));   
        xm->set("age", me->query("age"));
        xm->set("owner",me);
        me->set("rumo",xm);
        xm->move(environment(me));
        me->kill_ob(xm);
        xm->fight_ob(me);
        message_vision("$N����к�Ȼ����$n��ȭ���Լ����������ɵô��һ����\n",me,xm);
        call_out("qiangjie",600);
}
        
void destructing(object ob)
{
        if(ob)
                destruct(ob);
}

int do_get(string arg)
{
        string temp,obj;
        object yl;
        object me = this_player();
        object ob=this_object();

        if(arg)
        {
                if(arg=="all" || arg=="ALL")
                        return 1;
                if(ob==present(arg, environment(ob)))
                {
                        if(query("zhuyao"))
                                return notify_fail("���ܰᶯ������ҩ��¯�ӡ�\n");
                }
                else
                {
if(sscanf(arg,"%s from %s",temp,obj)==2)
                        {
                                if(objectp(yl=present(obj, me))||
                                   objectp(yl=present(obj, environment(me))))
                                {
                                        if(yl==ob)
                                                return notify_fail("ֻ�ܴ�ҩ¯��ȡ(qu)������\n");
                                }
                        }
                }
        }
        return 0;
}

int do_put(string arg)
{
        string temp,obj;
        object yl;
        object me = this_player();

        if(arg)
        {
                if(sscanf(arg,"%s in %s",temp,obj)==2)
                {
                        if(objectp(yl=present(obj, me))||
                           objectp(yl=present(obj, environment(me))))
                        {
                                if(yl==this_object())
                                        return notify_fail("ֻ����ҩ¯���(fang)������\n");
                        }
                }
        }
        return 0;
}

int do_fang(string arg)
{
        object me = this_player();
        object yc;
if(!arg)
                return notify_fail("��Ҫ��ʲô��ҩ¯��ȥ��\n");
        if(!objectp(yc=present(arg, me)))
                return notify_fail("������û��"+arg+"���ֶ�����\n");
        if(yc->query("id")!="yao cao")
                return notify_fail("�㲻�ܷ�"+yc->query("name")+"��ҩ¯��ȥ��\n");
        if(query("yaocai")>=9)
                return notify_fail("ҩ¯�Ѿ���ҩ�������ˡ�\n");
            message_vision(HIY+"\n$N"+HIY+"��һ��ҩ�ݷŽ�ҩ¯��\n"NOR,me);
        yc->move(this_object());
        yc->set("stime",uptime());
        add("yaocai",1);
        set("zhuyao",1);
        return 1;       
}

int do_qu(string arg)
{
        object me = this_player();
        object yc,yl;

        if(!arg)
                return notify_fail("��Ҫ��ҩ¯����ʲô������\n");
        /*if(!objectp(yl=present(arg, environment(me))))
                return notify_fail("ҩ¯��������ߡ�\n");*/
        yl=this_object();
        if(!objectp(yc=present(arg, yl)))
                return notify_fail("ҩ¯��û��"+arg+"���ֶ�����\n");
        if(yc->query("id")!="yao cao")
                return notify_fail("�㲻�ܴ�ҩ¯����"+yc->query("name")+"��\n");
           message_vision(HIY+"\n$N"+HIY+"��ҩ¯���ó���һ��ҩ�ݡ�\n"NOR,me);
        yc->add("times",uptime()-yc->query("stime"));
        yc->move(me);
        add("yaocai",-1);
        if(query("yaocai")<=0)
                set("zhuyao",0);        
        return 1;       
}

int do_kan(string arg)
{
        object me=this_player();
        object yl=this_object();
        object* obs;
        object yc;
        int se,i,j;
        string msg,pre;
        string * day=({ "һ","��","��","��","��","��","��","��","��"});
        string * sc=({ "һ","��","��","��","��","��","��","��","��","ʮ","ʮһ"});

        if(arg)
        {
                if(!objectp(yc=present(arg, yl)))
                        return notify_fail("ҩ¯��û��"+arg+"���ֶ�����\n");
                if(!yc->query("bad"))
                {
                        se=yc->query("times")+uptime()-yc->query("stime");
                        if(se<=MAXS)
                        {
                                i=se/240;
                                se=se-i*240;
                                pre="("+yc->query("8type")+yc->query("5type")+"��)";
                                msg="�Ѿ�������";
                                if(i>0)
                                        msg=msg+day[i-1]+"��";
                                i=se/20;
                                if(i>0)
                                        msg=msg+sc[i-1]+"��ʱ����\n";
                                else if(msg=="�Ѿ�������")
                                        msg=msg+"һ��ʱ��������\n";
                                msg=pre+msg;
                        }
                        else
                        {
                                msg="��\n";
                                yc->set("name","�廵�˵�"+yc->query("name"));
                                yc->set("bad",1);
                                tell_object(me,yc->name(1)+msg);
                                destruct(yc);
                                add("yaocai",-1);
return 1;
                        }
                }
                else
                        msg="��\n";
                tell_object(me,yc->name(1)+msg);
                return 1;
        }       
        obs=all_inventory(yl);
        for(j=0;j<sizeof(obs);j++)
        {
                yc=obs[j];
                if(!yc->query("bad"))
                {
                        se=yc->query("times")+uptime()-yc->query("stime");
                        if(se<=MAXS)
                        {
                                i=se/240;
                                se=se-i*240;
                                pre="("+yc->query("8type")+yc->query("5type")+"��)";
                                msg="�Ѿ�������";
                                if(i>0)
                                        msg=msg+day[i-1]+"��";
                                i=se/20;
                                if(i>0)
                                        msg=msg+sc[i-1]+"��ʱ����\n";
                                else if(msg=="�Ѿ�������")
                                        msg=msg+"һ��ʱ��������\n";
                                msg=pre+msg;
                        }
                        else
                        {
                                msg="��\n";
                                yc->set("name","�廵�˵�"+yc->query("name"));
                                yc->set("bad",1);
                                tell_object(me,yc->name(1)+msg);
                                destruct(yc);
                                add("yaocai",-1);
                                continue;
                        }
                }
else
                        msg="��\n";
                tell_object(me,yc->name(1)+msg);
        }
        return 1;
}

int do_quyao(string arg)
{
        object me=this_player(),yl=this_object(),* obs,yao;
        mapping ycl=(["��":0,"��":0,"��":0,"ˮ":0,"ľ":0]);
        //mapping 8type=(["Ǭ":0,"��":0,"��":0,"��":0,"��":0,"��":0,"��":0,"��":0]);
        mapping yc=([]);
        string type5,type88,* order;
        string* num=({"0","1","2","3","4","5","6","7","8"});
        string* type=({"��","��","��","ˮ","ľ"});
        string* type8=({"Ǭ","��","��","��","��","��","��","��"});
        int i,se,j,sl,sllv,polv,sesx,add,total,k;
        string msg;
        mapping myfam;

        myfam = (mapping)me->query("family");
        if(!myfam || myfam["family_name"] != "������")
        {
                return 0;
        }
        sllv=me->query_skill("shenlong-yaoli",1);
        polv=me->query_skill("poison",1);
        sesx=(sllv+polv/2)*72/10;
        if(sllv<101 || polv<101)
                return notify_fail("�������ҩ��ѧ�Ͷ������˽⻹������������ҩ��\n");
        if(yl->query("owner")!=me)
                return notify_fail("�㵽���˵�ҩ¯��ȥ��ʲô��\n");
        if(me->query("rumo")!=0)
                return notify_fail("���ȿ˷�����ħ��˵��\n");
        obs=all_inventory(yl);
        if(sizeof(obs)==0)
                return notify_fail("ҩ¯��û�ж�����\n");
        msg=me->query("id");
        for(i=0;i<sizeof(obs);i++)
{
                if(obs[i]->query("id")!="yao cao")
                        continue;
                se=obs[i]->query("times")+uptime()-obs[i]->query("stime");
                if(se>MAXS)
                {
                        obs[i]->set("name","�廵�˵�"+obs[i]->query("name"));
                        obs[i]->set("bad",1);
                        destruct(obs[i]);
                        add("yaocai",-1);
                        continue;
                }
                if(se>sesx)
                        se=sesx;
                type5=obs[i]->query("5type");
                type88=obs[i]->query("8type");
                msg=sprintf("%s %s%s:%d",msg,type5,type88,se);
                if(sizeof(yc)==0)
                {
                        yc=([ type5:([type88:([num[i]:se])])]);
                }
                else
                {
                        if( undefinedp(yc[type5]) )
                        {
                                yc[type5]=([type88:([num[i]:se])]);
                        }
                        else if( undefinedp(yc[type5][type88]))
                        {
                                yc[type5][type88]=([num[i]:se]);
                        }
                        else
                        {
                                yc[type5][type88][num[i]]=se;
                        }       
                }
                destruct(obs[i]);
                add("yaocai",-1);
        }
        add=0;
for(i=0;i<5;i++)
        {
                if( undefinedp(yc[type[i]]))
                        continue;
                else if(sizeof(yc[type[i]])>=8)
                {
                        sl=10000;
                        for(j=0;j<8;j++)
                        {
                                if( undefinedp(yc[type[i]][type8[j]]))
                                        continue;
                                order=keys(yc[type[i]][type8[j]]);
                                if(yc[type[i]][type8[j]][order[0]]<sl)
                                        sl=yc[type[i]][type8[j]][order[0]];
                                map_delete(yc[type[i]][type8[j]],order[0]);
                                if(sizeof(yc[type[i]][type8[j]])==0)
                                        map_delete(yc[type[i]],type8[j]);
                        }
                        ycl[type[i]]=sl*64;
                }
                else
                {
                        for(k=0;k<2;k++)
                        {
                                while(1)
                                {
                                        for(j=k;j<8;j++,j++)
                                        {
                                                if(undefinedp(yc[type[i]][type8[j]]))
                                                        break;
                                        }
                                        if(j>=8)
                                        {
                                                sl=10000;
                                                for(j=k;j<8;j++,j++)
                                                {
                                                        if( undefinedp(yc[type[i]][type8[j]]))
                                                                continue;
order=keys(yc[type[i]][type8[j]]);
                                                        if(yc[type[i]][type8[j]][order[0]]<sl)
                                                                sl=yc[type[i]][type8[j]][order[0]];
                                                        map_delete(yc[type[i]][type8[j]],order[0]);
                                                        if(sizeof(yc[type[i]][type8[j]])==0)
                                                                map_delete(yc[type[i]],type8[j]);
                                                }
                                                ycl[type[i]]=ycl[type[i]]+sl*16;
                                        }
                                        else
                                                break;
                                }
                        }
                        for(k=0;k<4;k++)
                        {
                                while(1)
                                {
                                        for(j=k*2;j<k*2+2;j++)
                                        {
                                                if(undefinedp(yc[type[i]][type8[j]]))
                                                        break;
                                        }
                                        if(j>=k*2+2)
                                        {
                                                sl=10000;
                                                for(j=k*2;j<k*2+2;j++)
                                                {
                                                        if( undefinedp(yc[type[i]][type8[j]]))
                                                                continue;
                                                        order=keys(yc[type[i]][type8[j]]);
                                                        if(yc[type[i]][type8[j]][order[0]]<sl)
                                                                sl=yc[type[i]][type8[j]][order[0]];
                                                        map_delete(yc[type[i]][type8[j]],order[0]);
                                                        if(sizeof(yc[type[i]][type8[j]])==0)
                                                                map_delete(yc[type[i]],type8[j]);
                                                }
                                                ycl[type[i]]=ycl[type[i]]+sl*4;
                                        }
                                        else
                                                break;
}
                        }
                }
                for(j=0;j<8;j++)
                {
                        if( undefinedp(yc[type[i]][type8[j]]))
                                        continue;                                                       order=keys(yc[type[i]][type8[j]]);
                        for(k=0;k<sizeof(order);k++)
                        {
                                ycl[type[i]]=ycl[type[i]]+yc[type[i]][type8[j]][order[k]];
                                map_delete(yc[type[i]][type8[j]],order[k]);
                        }
                        map_delete(yc[type[i]],type8[j]);
                }
                add+=ycl[type[i]];
        }
        total=add;
        add/=200;
        if(add>100)
                add=100;
        me->improve_skill("shenlong-yaoli",add,0);
        me->improve_skill("poison",add,0);
        yao=new("/d/sld/npc/obj/yaowan");
        if(!objectp(yao))
                return notify_fail("��ϧ�����ҩ���廵�ˡ�\n");
        msg=msg+" "+file_name(yao);
        j=0;k=0;
        yao->set("types",0);
        for(i=0;i<5;i++)
        {
                if(ycl[type[i]]<total*1/20)
                        continue;
                yao->add("types",1);
                if(type[i]=="��")
                {
                        yao->set(type[i],ycl[type[i]]/100);
                        msg=sprintf("%s %s:%d",msg,type[i],ycl[type[i]]/100);
                }
                else
{
                        yao->set(type[i],ycl[type[i]]/10);
                        msg=sprintf("%s %s:%d",msg,type[i],ycl[type[i]]/10);
                }
                if(ycl[type[i]]>=total*7/10)
                        k=i+1;
                else if((ycl[type[i]]>=total*19/100) && (ycl[type[i]]<=total*21/100))
                        j++;
        }
        if(k>0)
        {
                yao->set("poison",type[k-1]);
                yao->set("zycs",ycl[type[k-1]]/1000);
                msg=sprintf("%s %s::%d",msg,type[k-1],ycl[type[k-1]]/1000);
        }
        else if(j==5)
        {
                yao->set("poison","ȫ");
                yao->set("zycs",total/1000);
                msg=sprintf("%s ȫ::%d",msg,total/1000);        
        }
        msg=msg+"��\n";
//	write_file("/u/emnil/makeyao",msg);
        write("���������ҩ���ʲôӢ�����֣�(ȱʡ��danyao)");
	yao->move(me);
        input_to("yao_id",0,yao);
        return 1;
}

void yao_id(string arg,object yao)
{
        if(arg && arg!="")
                yao->set("id",arg);
        else
                yao->set("id","danyao");
        write("���������ҩ���ʲô�������֣�(ȱʡ����ҩ)");
        input_to("yao_name",0,yao);
}

void yao_name(string arg,object yao)
{
        yao->set_name(HIG "��ҩ" NOR, ({yao->query("id"),"yao","dan"}));
if(arg && arg!="")
                yao->set("name",arg);
        write("���������������ҩ��(ȱʡ������һ�������̶������Ƶĵ�ҩ��)");
        input_to("yao_long",0,yao);
}

void yao_long(string arg,object yao)
{
    int i,add,qnadd;
    object me=this_player();

if(arg && arg!="")
              yao->set("long",arg+"\n");
        message_vision(HIY+"\n$N"+HIY+"��ҩ¯���ó���һ��ҩ��\n"NOR,me);
        if(!yao->move(me))
                yao->move(environment(me));
        if((add=me->query("mkyexp"))!=0)
        {
                i=me->query("max_pot")-me->query("potential");
                qnadd=add/2;
                if ( i<qnadd) qnadd = i;
                
                me->add("combat_exp",add);
                me->add("potential",qnadd);
                me->add("shen",-add*2);
                me->delete("mkyexp");

                tell_object(me,"��սʤ��ħ�������"+add+"�㾭�飬"+qnadd+"��Ǳ�ܣ�"+add*2+"�㸺��\n");
        }
}
