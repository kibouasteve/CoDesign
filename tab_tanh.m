tab=[];
x=0;
for i =1:8354
    tab(:,i)=(1.7159*tanh(0.66666667*x));
    x=x+0.001;
    fprintf('%f,',x);
end

fprintf('float tab[8354] = { \n');
for i =1:8354
    if(mod(i,10)==0)
        fprintf('\n');
    end
    fprintf('%f,',tab(i));
end
fprintf('\n }');
plot(tab)